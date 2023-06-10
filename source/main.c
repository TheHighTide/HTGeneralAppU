#include <stdint.h>
#include <stdbool.h>
#include <malloc.h>

#include <coreinit/thread.h>
#include <coreinit/time.h>
#include <coreinit/screen.h>
#include <coreinit/cache.h>
#include <whb/log_cafe.h>
#include <whb/log_udp.h>
#include <whb/log.h>
#include <whb/proc.h>
#include <vpad/input.h>

#include <menus.h>


int main(int argc, char** argv) {
   int tv_menu = 0;
   int drc_menu = 0;

   WHBLogCafeInit();
   WHBLogUdpInit();
   WHBLogPrint("HTGA Loading...");
   WHBProcInit();
   OSScreenInit();
   size_t tvBufferSize = OSScreenGetBufferSizeEx(SCREEN_TV); // Height: 0 to 29
   size_t drcBufferSize = OSScreenGetBufferSizeEx(SCREEN_DRC);
   WHBLogPrintf("Will save 0x%X bytes of memory for the TV, " \
               "and will save 0x%X bytes of memory for the DRC.",
               tvBufferSize, drcBufferSize);

   void* tvBuffer = memalign(0x100, tvBufferSize);
   void* drcBuffer = memalign(0x100, drcBufferSize);

   if (!tvBuffer || !drcBuffer) {
      WHBLogPrint("Not enough memory!");
      if (tvBuffer) free(tvBuffer);
      if (drcBuffer) free(drcBuffer);
      OSScreenShutdown();
      WHBProcShutdown();
      WHBLogPrint("Exiting...");
      WHBLogCafeDeinit();
      WHBLogUdpDeinit();
      return 1;
   }

   OSScreenSetBufferEx(SCREEN_TV, tvBuffer);
   OSScreenSetBufferEx(SCREEN_DRC, drcBuffer);
   OSScreenEnableEx(SCREEN_TV, true);
   OSScreenEnableEx(SCREEN_DRC, true);

   while(WHBProcIsRunning()){
      VPADStatus vpad;
      VPADRead(0, &vpad, 1, NULL);
      OSScreenClearBufferEx(SCREEN_TV, 0x00000000);
      OSScreenClearBufferEx(SCREEN_DRC, 0x00000000);

      if (vpad.trigger & VPAD_BUTTON_MINUS){
         tv_menu = 1;
         drc_menu = 1;
      }
      else if (vpad.trigger & VPAD_BUTTON_PLUS){
         tv_menu = 2;
         drc_menu = 2;
      }
      else if (vpad.trigger & VPAD_BUTTON_B){
         tv_menu = 0;
         drc_menu = 0;
      }

      if (tv_menu == 0){DisplayTVMenu(0);}
      if (tv_menu == 1){DisplayTVMenu(1);}

      if (drc_menu == 0){DisplayDRCMenu(0);}
      if (drc_menu == 1){DisplayDRCMenu(1);}

      DCFlushRange(tvBuffer, tvBufferSize);
      DCFlushRange(drcBuffer, drcBufferSize);
      OSScreenFlipBuffersEx(SCREEN_TV);
      OSScreenFlipBuffersEx(SCREEN_DRC);

      OSSleepTicks(OSSecondsToTicks(0.1f));
   }
   if (tvBuffer) free(tvBuffer);
   if (drcBuffer) free(drcBuffer);

   OSScreenShutdown();
   WHBProcShutdown();

   WHBLogPrint("Exiting...");
   WHBLogCafeDeinit();
   WHBLogUdpDeinit();

   return 1;
}
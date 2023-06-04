#include <coreinit/thread.h>
#include <coreinit/time.h>

#include <whb/proc.h>
#include <whb/log.h>
#include <whb/log_console.h>

#include <vpad/input.h>

#include <menu.h>
#include <schedule.h>
#include <systemtext.h>

// Definitions
#define SCREEN_WIDTH  854
#define SCREEN_HEIGHT 480

int
main(int argc, char **argv)
{
   WHBProcInit();
   WHBLogConsoleInit();

   DisplayMenu(0);

   while(WHBProcIsRunning()) {
      VPADStatus vpad;
      VPADRead(0, &vpad, 1, NULL);

      if (vpad.trigger & VPAD_BUTTON_PLUS){
         WHBLogPrintf("A = Current HighTide Project");
         OSSleepTicks(OSMillisecondsToTicks(100));
         WHBLogConsoleDraw();
         WHBLogPrintf("B = App Info");
         OSSleepTicks(OSMillisecondsToTicks(100));
         WHBLogConsoleDraw();
         WHBLogPrintf("X = Planned Updates");
         OSSleepTicks(OSMillisecondsToTicks(100));
         WHBLogConsoleDraw();
         WHBLogPrintf("Home = Exit");
         OSSleepTicks(OSMillisecondsToTicks(100));
         WHBLogConsoleDraw();
         PlaceDivider(0);
      }
      if (vpad.trigger & VPAD_BUTTON_A){
         DisplayCurrentProject();
         PlaceDivider(0);
      }
      if (vpad.trigger & VPAD_BUTTON_B){
         DisplayAppInfo();
         PlaceDivider(0);
      }
      if (vpad.trigger & VPAD_BUTTON_X){
         DisplayPlannedUpdates();
         PlaceDivider(0);
      }
      WHBLogConsoleDraw();
      OSSleepTicks(OSMillisecondsToTicks(10));
   }

   WHBLogPrintf("Exiting... good bye.");
   WHBLogConsoleDraw();
   OSSleepTicks(OSMillisecondsToTicks(1000));

   WHBLogConsoleFree();
   WHBProcShutdown();
   return 0;
}
void DisplayTVMenu(int menuID){
    if (menuID == 0){ // Main Menu
        OSScreenPutFontEx(SCREEN_TV, 30, 0, "HighTide General App");
        OSScreenPutFontEx(SCREEN_TV, 39, 1, "U");
        OSScreenPutFontEx(SCREEN_TV, 0, 2, "--------------------------------------------------------------------------------");
        OSScreenPutFontEx(SCREEN_TV, 20, 29, "Please look at the gamepad for controls!");
    }
    else if (menuID == 1){ // HighTide General App U Info
        OSScreenPutFontEx(SCREEN_TV, 30, 0, "HighTide General App");
        OSScreenPutFontEx(SCREEN_TV, 39, 1, "U");
        OSScreenPutFontEx(SCREEN_TV, 0, 2, "--------------------------------------------------------------------------------");
        OSScreenPutFontEx(SCREEN_TV, 0, 3, "The HighTide General App (HTGA) is a useful app full of functions and tools that");
        OSScreenPutFontEx(SCREEN_TV, 0, 4, "people can use to complete common tasks. Some of these tasks are:");
        OSScreenPutFontEx(SCREEN_TV, 0, 5, "- Get System Info");
        OSScreenPutFontEx(SCREEN_TV, 0, 6, "- Start a Stop Watch");
        OSScreenPutFontEx(SCREEN_TV, 0, 8, "This app is always free and will be free for anyone to download for their WiiU");
        OSScreenPutFontEx(SCREEN_TV, 0, 9, "system. More features will and are going to be added to this app to meet the");
        OSScreenPutFontEx(SCREEN_TV, 0, 10, "users criteria!");
        OSScreenPutFontEx(SCREEN_TV, 20, 29, "Please look at the gamepad for controls!");
    }
}

void DisplayDRCMenu(int menuID){
    if (menuID == 0){ // Main Control Menu
        OSScreenPutFontEx(SCREEN_DRC, 0, 1, "MINUS: Application Info");
        OSScreenPutFontEx(SCREEN_DRC, 0, 2, "HOME: Exit Application");
    }
    else if (menuID == 1){
        OSScreenPutFontEx(SCREEN_DRC, 0, 1, "MINUS: Application Info");
        OSScreenPutFontEx(SCREEN_DRC, 0, 2, "B: Return");
        OSScreenPutFontEx(SCREEN_DRC, 0, 3, "HOME: Exit Application");
    }
}

char plannedUpdates[] = "Switch from LogConsole based text to GFX based text (Better text rendering)";

void DisplayAppInfo(){
    WHBLogPrintf("Welcome to the HighTide General App U! This is an app that allows you to keep");
    WHBLogPrintf("track with what HighTide does without any hassel at all. This app is extremely");
    WHBLogPrintf("easy to use and should be able to be used without any issues!");
}

void DisplayPlannedUpdates(){
    WHBLogPrintf("Planned Updates Are:");
    WHBLogPrintf("%s", plannedUpdates);
}

void PlaceDivider(int type){
    if (type == 0){
        WHBLogPrintf("------------------------------------------------------");
    }
    else if (type == 1){
        WHBLogPrintf("______________________________________________________");
    }
    else if (type == 2){
        WHBLogPrintf("======================================================");
    }
    else if (type == 3){
        WHBLogPrintf("/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\");
    }
    else{
        WHBLogPrintf("ERROR NO MATCHING DIVIDER WITH THAT ID!");
    }
}
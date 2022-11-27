# UnrealEngineDebugging1
Trying to fix an issue (C++).
CPP_Interact c++ class derives from AActor class, CPP_InventoryBar derives from UWidget class.

Trying to call a CPP_InventoryBar function (UpdateInventoryBarSlot) from CPP_Interact class. Made an instance of CPP_InventoryBar in CPP_Interact but the 
variables inside the called function are null or 0. Even though those variables are declared and working, if the same function called from itself (from the 
class it was made in) then it works and the variables are not null.

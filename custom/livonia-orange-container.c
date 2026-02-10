static Object SpawnObject(string type, vector position, vector orientation, float scale = 1.0)
{
    Object obj;
    if (type.Contains(".p3d")) {
        obj = GetGame().CreateStaticObjectUsingP3D(type, position, orientation, scale, false);
    } else {        
        obj = GetGame().CreateObjectEx(type, position, ECE_SETUP | ECE_CREATEPHYSICS | ECE_NOLIFETIME | ECE_NOPERSISTENCY_WORLD | ECE_NOPERSISTENCY_CHAR);
    }

    if (!obj) {
        Error("Failed to create object " + type);
        return null;
    }

    obj.SetPosition(position);
    obj.SetOrientation(orientation);
    obj.SetOrientation(obj.GetOrientation());
    obj.SetScale(scale);
    obj.Update();
	obj.SetAffectPathgraph(true, false);
	if (obj.CanAffectPathgraph()) {
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().UpdatePathgraphRegionByObject, 100, false, obj);
    } 

    return obj;
}

// Paste anything below this line into the bottom of your 'void main()' function


// Created Objects
SpawnObject("Land_ContainerLocked_Orange_DE", "4904.711914 525.979004 2114.752441", "151.322067 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Misc_Gunrack", "4904.088379 525.245667 2114.620361", "151.322083 -0.000000 -0.000000", 0.999999);
SpawnObject("Aug", "4904.463867 525.287476 2114.492188", "151.322083 -0.000000 90.000000", 0.999999);
SpawnObject("M79", "4903.619141 525.332275 2114.822266", "151.322083 -0.000000 90.000000", 0.999999);
SpawnObject("AKM", "4904.421387 525.400391 2114.674805", "151.322083 -0.000000 90.000000", 0.999999);
SpawnObject("M14", "4904.080566 525.350952 2114.734375", "151.322083 -0.000000 90.000000", 0.999999);
SpawnObject("FAL", "4904.257813 525.293701 2114.941406", "151.322083 -0.000000 90.000000", 0.999999);
SpawnObject("SV98", "4904.217285 525.302124 2114.462402", "151.322083 -0.000000 90.000000", 0.999999);
SpawnObject("M4A1", "4904.134766 525.394226 2115.101807", "151.322083 -0.000000 90.000000", 0.999999);
SpawnObject("ASVAL", "4904.297852 525.290527 2114.278076", "151.322083 -0.000000 90.000000", 0.999999);
SpawnObject("SVD", "4903.980469 525.303589 2114.919434", "151.322067 0.000000 90.000000", 0.999999);
SpawnObject("ImprovisedExplosive", "4904.421387 524.880554 2113.858887", "30.640009 0.000000 0.000000", 0.999999);
SpawnObject("RemoteDetonator", "4903.782715 524.926880 2115.304199", "127.322121 89.972015 0.000007", 0.999999);


// Uncomment if you want to export loot from newly added buildings
// Position, Radius (increase if you have a larger map than Chernarus)
// GetCEApi().ExportProxyData(Vector(7500, GetGame().SurfaceY(7500, 7500), 7500), 20000);

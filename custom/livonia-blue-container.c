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
SpawnObject("Land_ContainerLocked_Blue_DE", "9001.625000 299.203003 6531.597168", "-136.072800 0.000000 0.000000", 0.999999);
SpawnObject("StaticObj_Misc_Gunrack", "9001.312500 298.469666 6532.151855", "-136.072754 -0.000000 0.000000", 0.999997);
SpawnObject("Aug", "9001.301758 298.511475 6531.756348", "-136.072754 -0.000000 90.000000", 0.999997);
SpawnObject("M79", "9001.365234 298.556274 6532.660156", "-136.072754 -0.000000 90.000000", 0.999997);
SpawnObject("AKM", "9001.463867 298.624390 6531.850586", "-136.072754 -0.000000 90.000000", 0.999997);
SpawnObject("M14", "9001.418945 298.574951 6532.193359", "-136.072754 -0.000000 90.000000", 0.999997);
SpawnObject("FAL", "9001.669922 298.517700 6532.085938", "-136.072754 -0.000000 90.000000", 0.999997);
SpawnObject("SV98", "9001.200195 298.526123 6531.981934", "-136.072754 -0.000000 90.000000", 0.999997);
SpawnObject("M4A1", "9001.786133 298.618225 6532.251465", "-136.072754 -0.000000 90.000000", 0.999997);
SpawnObject("ASVAL", "9001.047852 298.514526 6531.850586", "-136.072754 -0.000000 90.000000", 0.999997);
SpawnObject("SVD", "9001.566406 298.527588 6532.344238", "-136.072769 -0.000000 90.000000", 0.999998);
SpawnObject("ImprovisedExplosive", "9000.685547 298.104553 6531.606934", "103.245110 0.000000 -0.000000", 0.999997);
SpawnObject("RemoteDetonator", "9001.874023 298.150879 6532.648438", "-160.072708 89.965729 0.000003", 0.999997);


// Uncomment if you want to export loot from newly added buildings
// Position, Radius (increase if you have a larger map than Chernarus)
// GetCEApi().ExportProxyData(Vector(7500, GetGame().SurfaceY(7500, 7500), 7500), 20000);

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
SpawnObject("Land_ContainerLocked_Yellow_DE", "8935.351563 473.942047 2068.509033", "126.222763 0.000000 -0.000000", 0.999999);
SpawnObject("StaticObj_Misc_Gunrack", "8934.843750 473.208710 2068.125000", "126.222794 -0.000000 -0.000000", 0.999998);
SpawnObject("Aug", "8935.237305 473.250519 2068.167969", "126.222794 -0.000000 90.000000", 0.999998);
SpawnObject("M79", "8934.333008 473.295319 2068.109131", "126.222794 -0.000000 90.000000", 0.999998);
SpawnObject("AKM", "8935.122070 473.363434 2068.315674", "126.222794 -0.000000 90.000000", 0.999998);
SpawnObject("M14", "8934.788086 473.313995 2068.225098", "126.222794 -0.000000 90.000000", 0.999998);
SpawnObject("FAL", "8934.861328 473.256744 2068.487793", "126.222794 -0.000000 90.000000", 0.999998);
SpawnObject("SV98", "8935.027344 473.265167 2068.036865", "126.222794 -0.000000 90.000000", 0.999998);
SpawnObject("M4A1", "8934.681641 473.357269 2068.581055", "126.222794 -0.000000 90.000000", 0.999998);
SpawnObject("ASVAL", "8935.177734 473.253571 2067.903564", "126.222794 -0.000000 90.000000", 0.999998);
SpawnObject("SVD", "8934.619141 473.266632 2068.350342", "126.222778 -0.000000 90.000000", 0.999998);
SpawnObject("ImprovisedExplosive", "8935.467773 472.843597 2067.576904", "5.540701 0.000000 0.000000", 0.999998);
SpawnObject("RemoteDetonator", "8934.276367 472.889923 2068.614746", "102.222832 89.965729 0.000008", 0.999998);


// Uncomment if you want to export loot from newly added buildings
// Position, Radius (increase if you have a larger map than Chernarus)
// GetCEApi().ExportProxyData(Vector(7500, GetGame().SurfaceY(7500, 7500), 7500), 20000);

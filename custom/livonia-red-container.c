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
SpawnObject("Land_ContainerLocked_Red_DE", "5598.630859 421.912903 3749.000732", "-109.399200 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Misc_Gunrack", "5598.601074 421.179535 3749.637451", "-109.399200 0.000000 -0.000000", 1);
SpawnObject("Aug", "5598.414063 421.221375 3749.287354", "-109.399200 0.000000 90.000000", 1);
SpawnObject("AKM", "5598.601074 421.334259 3749.299805", "-109.399200 0.000000 90.000000", 1);
SpawnObject("FAL", "5598.890625 421.227539 3749.418457", "-109.399200 0.000000 90.000000", 1);
SpawnObject("M4A1", "5599.068848 421.328094 3749.514160", "-109.399200 0.000000 90.000000", 1);
SpawnObject("SV98", "5598.424316 421.235992 3749.535645", "-109.399200 0.000000 90.000000", 1);
SpawnObject("ASVAL", "5598.229492 421.224396 3749.485840", "-109.399200 0.000000 90.000000", 1);
SpawnObject("M14", "5598.714844 421.284821 3749.626709", "-109.399200 0.000000 90.000000", 1);
SpawnObject("M79", "5598.875977 421.266174 3750.068115", "-109.399200 0.000000 90.000000", 1);
SpawnObject("SVD", "5598.913574 421.237457 3749.695557", "-109.399200 0.000000 90.000000", 1);
SpawnObject("ImprovisedExplosive", "5597.795898 420.814423 3749.431396", "129.918716 0.000000 -0.000000", 1);
SpawnObject("RemoteDetonator", "5599.325195 420.860718 3749.828613", "-133.399185 89.980209 -0.000002", 0.999999);


// Uncomment if you want to export loot from newly added buildings
// Position, Radius (increase if you have a larger map than Chernarus)
// GetCEApi().ExportProxyData(Vector(7500, GetGame().SurfaceY(7500, 7500), 7500), 20000);

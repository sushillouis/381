using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DistanceRaycastSelectable : SelectedTracker {

	RaycastHit hit;

	void Update() {
		// NOTE: It would be a better design (more performant) to have this code run in some kind of SelectionMgr
		if(Input.GetMouseButtonDown(0)){
			var ray = Camera.main.ScreenPointToRay(Input.mousePosition);
			if(Physics.Raycast(ray, out hit)) {
				Vector3 pos = hit.point;
				float smallestSquareDistance = Mathf.Infinity;

				// NOTE: Don't do this!!! Only loop over an array of entities you are interested in
				//	not every single GameObject, this code will ANNIHILATE your performance
				foreach(GameObject obj in FindObjectsOfType<GameObject>())
					smallestSquareDistance = Mathf.Min((obj.transform.position - pos).sqrMagnitude, smallestSquareDistance);

				Debug.Log(smallestSquareDistance);

				if(smallestSquareDistance > (1.3 * 1.3)) {
					// SelectionMgr.instance.MarkSelected(null);
				} else if((transform.position - pos).sqrMagnitude == smallestSquareDistance)
					SelectionMgr.instance.MarkSelected(this);

			}
		}

		// Have to call update of the base class to facilate material changes
		base.Update();
	}
	
}

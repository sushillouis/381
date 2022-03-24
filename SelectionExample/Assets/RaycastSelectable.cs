using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(Collider))]
public class RaycastSelectable : SelectedTracker {

	RaycastHit hit;

	void Update() {
		if(Input.GetMouseButtonDown(0)){
			var ray = Camera.main.ScreenPointToRay(Input.mousePosition);
			if(Physics.Raycast(ray, out hit))
				if(hit.collider.gameObject == gameObject)
					SelectionMgr.instance.MarkSelected(this);
		}

		// Have to call update of the base class to facilate material changes
		base.Update();
	}
	
}

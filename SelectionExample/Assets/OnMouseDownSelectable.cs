using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(Collider))]
public class OnMouseDownSelectable : SelectedTracker {

	void OnMouseDown(){
		SelectionMgr.instance.MarkSelected(this);
	}

}

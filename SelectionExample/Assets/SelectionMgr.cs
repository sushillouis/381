using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SelectionMgr : MonoBehaviour {

	public static SelectionMgr instance;
	void Awake(){
		instance = this;
	}

	public void MarkSelected(SelectedTracker tracker){
		foreach (var trk in FindObjectsOfType<SelectedTracker>())
			trk.isSelected = false;

		tracker.isSelected = true;
	}
}

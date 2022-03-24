using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(MeshRenderer))]
public class SelectedTracker : MonoBehaviour {
	[SerializeField] Material selected, unselected;
	public bool isSelected;

	MeshRenderer meshRenderer;

	void Start(){
		meshRenderer = GetComponent<MeshRenderer>();
	}

	// Update is called once per frame
	public void Update() {
		if(isSelected)
			meshRenderer.material = selected;
		else
			meshRenderer.material = unselected;
	}
}

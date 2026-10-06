#pragma once

namespace features::chams
{
	using DrawObjectFn = void*( __fastcall* )( void*, void*, void*, int, void*, void*, void* );

	// Creates the custom materials. Returns false if the signatures are outdated.
	bool init( );
	bool ready( );
	const char* status( );

	// Called from the CAnimatableSceneObjectDesc draw hook.
	void* onDrawObject( DrawObjectFn original, void* desc, void* renderContext, void* sceneData, int count, void* sceneView, void* sceneLayer, void* unk );
}

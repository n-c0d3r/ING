#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING\Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	enum EngineState {

		NONE_ENGINE_STATE,

		CREATED_ENGINE_STATE,
		
		INITIALIZED_ENGINE_STATE,
		
		RUNNING_ENGINE_STATE,

		CLOSED_ENGINE_STATE

	};

}
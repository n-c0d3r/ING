#pragma once

/**
 *	Include Entry Point
 */
#include <ING/EntryPoint/EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	namespace ECS {

		struct ING_API Component
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			Component();
			~Component();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();

		};

	}

}
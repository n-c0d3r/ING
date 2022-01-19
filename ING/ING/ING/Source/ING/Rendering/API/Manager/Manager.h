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



/**
 *	Include APIFlag
 */
#include <ING\Rendering/API/APIFlag.h>



namespace ING {

	namespace Rendering {

		class API;

		class ING_API APIManager :
			public Singleton<APIManager>,
			public Square
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			APIManager();
			~APIManager();



			/**
			 *	Init, Run, Release Methods
			 */
		public:
			virtual bool Init()		override;
			virtual bool Run()		override;
			virtual bool Release()	override;



			/**
			 *	API Management Methods, Properties
			 */
		protected:
			APIFlag apiFlag;

			API* api;

		public:
			APIFlag GetAPIFlag() {

				return apiFlag;

			}

			API* GetAPI() {

				return api;

			}

		public:
			bool InitAPI();

		};

	}

}
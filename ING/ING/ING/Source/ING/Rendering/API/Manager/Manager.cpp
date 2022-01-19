
/**
 *	Include Header
 */
#include "Manager.h"



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Application Configuration
 */
#include <ING/Application/Configuration/Configuration.h>



 /**
  *	Include Utils
  */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include API
 */
#include <ING\Rendering/API/API.h>



/**
 *	Include APIs
 */
#include <ING\Rendering/API/DirectX11/API.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		APIManager::APIManager() {

			Application::GetInstance()->GetConfiguration()->Add<APIFlag>("ING::Rendering::APIManager::apiName");

			Application::GetInstance()->GetConfiguration()->Set<APIFlag>("ING::Rendering::APIManager::apiName", DIRECTX11_API_FLAG);

		}

		APIManager::~APIManager() {



		}



		/**
		 *	Init, Run, Release Methods
		 */
		bool APIManager::Init() {

			apiFlag = Application::GetInstance()->GetConfiguration()->Get<APIFlag>("ING::Rendering::APIManager::apiName");

			if (!InitAPI()) {

				Debug::Log("Cant Init Rendering API");

				return false;

			}

			return true;
		}

		bool APIManager::Run() {



			return true;
		}

		bool APIManager::Release() {

			if (api != nullptr) {

				api->Release();

			}

			return true;
		}



		/**
		 *	API Management Methods, Properties
		 */
		bool APIManager::InitAPI() {

			switch (apiFlag)
			{
			case NONE_API_FLAG:
				return false;
				break;
			case DIRECTX11_API_FLAG:

				api = new DirectX11::API();

				api->Init();

				break;
			default:
				break;
			}

		}

	}
}

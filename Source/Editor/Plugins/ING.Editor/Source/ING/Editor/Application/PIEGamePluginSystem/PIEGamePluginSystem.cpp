
/**
 *	Include Header
 */
#include "PIEGamePluginSystem.h"



 /**
  *	Include Utils
  */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Configuration
 */
#include <ING/Configuration/Configuration.h>



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Window
 */
#include <ING/Window/Window.h>



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Event
 */
#include <ING/Event/Event.h>



/**
 *	Include ApplicationComponent
 */
#include <ING/Application/Component/Component.h>



namespace ING {

	namespace Editor {

		/**
		 *	Constructors And Destructor
		 */
		ApplicationPIEGamePluginSystem::ApplicationPIEGamePluginSystem(IApplication* application) :
			IApplicationComponent(application, "PIEGamePluginSystem")
		{



		}

		ApplicationPIEGamePluginSystem::~ApplicationPIEGamePluginSystem()
		{



		}



		/**
		 *	Release Methods
		 */
		bool ApplicationPIEGamePluginSystem::Init()
		{



			return IApplicationComponent::Init();

		}

		void ApplicationPIEGamePluginSystem::Release()
		{

			IApplicationComponent::Release();

		}



		/**
		 *	Methods
		 */
		void	ApplicationPIEGamePluginSystem::Start() {

			IApplicationComponent::Start();

		}

		void	ApplicationPIEGamePluginSystem::PreUpdate() {

			IApplicationComponent::PreUpdate();

		}

		void	ApplicationPIEGamePluginSystem::Update() {

			IApplicationComponent::Update();

		}

		void	ApplicationPIEGamePluginSystem::LateUpdate() {

			IApplicationComponent::LateUpdate();

		}

		void	ApplicationPIEGamePluginSystem::PreRender() {

			IApplicationComponent::PreRender();

		}

		void	ApplicationPIEGamePluginSystem::Render() {

			IApplicationComponent::Render();

		}

		void	ApplicationPIEGamePluginSystem::LateRender() {

			IApplicationComponent::LateRender();

		}

	}
	
}
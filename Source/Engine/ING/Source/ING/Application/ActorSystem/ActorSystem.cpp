
/**
 *	Include Header
 */
#include "ActorSystem.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Event
 */
#include <ING/Event/Event.h>



/**
 *	Include Actor
 */
#include <ING/Actor/Actor.h>



/**
 *	Include ActorComponent
 */
#include <ING/Actor/Component/Component.h>



/**
 *	Include Reflection System
 */
#include <ING/Application/ReflectionSystem/ReflectionSystem.h>



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ApplicationActorSystem::ApplicationActorSystem(IApplication* application) :
		IApplicationComponent(application, "ActorSystem")
	{



	}

	ApplicationActorSystem::~ApplicationActorSystem() {



	}



	/**
	 *	Init, Release Methods
	 */
	bool ApplicationActorSystem::Init() {



		/**
		 *	Add Classes
		 */
		Reflection::Context* reflectionContext = GetApplication()->GetReflectionSystem()->GetContext();

		IActor::CreateType(reflectionContext);

		IActorComponent::CreateType(reflectionContext);



		return IApplicationComponent::Init();
	}

	void ApplicationActorSystem::Release() {



		/**
		 *	Release Classes
		 */
		Reflection::Context* reflectionContext = GetApplication()->GetReflectionSystem()->GetContext();

		IActor::ReleaseType(reflectionContext);

		IActorComponent::ReleaseType(reflectionContext);



		IApplicationComponent::Release();

	}



	/**
	 *	Methods
	 */
	void	ApplicationActorSystem::Start() {

		IApplicationComponent::Start();

	}

	void	ApplicationActorSystem::PreUpdate() {

		IApplicationComponent::PreUpdate();

	}

	void	ApplicationActorSystem::Update() {

		IApplicationComponent::Update();

	}

	void	ApplicationActorSystem::LateUpdate() {

		IApplicationComponent::LateUpdate();

	}

	void	ApplicationActorSystem::PreRender() {

		IApplicationComponent::PreRender();

	}

	void	ApplicationActorSystem::Render() {

		IApplicationComponent::Render();

	}

	void	ApplicationActorSystem::LateRender() {

		IApplicationComponent::LateRender();

	}

}

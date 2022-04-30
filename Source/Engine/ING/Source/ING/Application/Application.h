#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



 /**
  *	Include Utils
  */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	class Configuration;

	class ApplicationWindowManager;

	class ApplicationRenderingSystem;

	class IApplicationComponent;



	class ING_API IApplication
	{

		/**
		 *	Friend Classes
		 */
	public:
		friend class ApplicationManager;



		/**
		 *	Constructors And Destructor
		 */
	public:
		IApplication	(const WString& configPath);
		~IApplication	();



		/**
		 *	Init, Release Methods
		 */
	public:
		virtual bool Init	();
		virtual void Release();



		/**
		 *	Properties
		 */
	private:
		String						name;

		WString						configPath;

		Configuration*				configuration;

		ApplicationWindowManager*	windowManager;

		ApplicationRenderingSystem*	renderingSystem;

		std::unordered_map<String, unsigned int> name2ComponentIndexMap;
		std::vector<IApplicationComponent*> componentVector;

	public:
		const String&				GetName			() { return name; }

		const WString&				GetConfigPath	() { return configPath; }

		Configuration*				GetConfiguration() {return configuration; }

		ApplicationWindowManager*	GetWindowManager() { return windowManager; }

		ApplicationRenderingSystem*	GetRenderingSystem() { return renderingSystem; }

		IApplicationComponent*		GetComponent	(const String& name) { return componentVector[name2ComponentIndexMap[name]]; }

		IApplicationComponent*		GetComponent	(unsigned int index) { return componentVector[index]; }



		/**
		 *	Methods
		 */
	public:
		void						AddComponent	(IApplicationComponent* component);
		void						RemoveComponent	(IApplicationComponent* component);

		virtual void				Start();

		virtual void				PreUpdate();
		virtual void				Update();
		virtual void				LateUpdate();

		virtual void				PreRender();
		virtual void				Render();
		virtual void				LateRender();

	};

}
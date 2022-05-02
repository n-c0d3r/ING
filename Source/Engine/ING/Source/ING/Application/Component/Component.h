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

	class IApplication;



	class ING_API IApplicationComponent
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		IApplicationComponent	(IApplication* application, const String& name);
		~IApplicationComponent	();



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
		String			name;

		IApplication*		application;

	public:
		const String&	GetName			() { return name; }

		IApplication*		GetApplication	() { return application; }



		/**
		 *	Methods
		 */
	public:
		virtual void	Start();

		virtual void	PreUpdate();
		virtual void	Update();
		virtual void	LateUpdate();

		virtual void	PreRender();
		virtual void	Render();
		virtual void	LateRender();

	};

}
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



/**
 *	Include Language
 */
#include <ING/Scripting/Language/Language.h>



namespace ING {

	namespace Scripting {

		namespace CSharp {

			class ING_API Language : public ILanguage
			{

				/**
				 *	Constructors And Destructor
				 */
			public:
				Language();
				~Language();



				/**
				 *	Release Method
				 */
			public:
				virtual void Release() override;



				/**
				 *	Methods
				 */
			public:
				virtual std::string GetName() override;

			};

		}

	}

}
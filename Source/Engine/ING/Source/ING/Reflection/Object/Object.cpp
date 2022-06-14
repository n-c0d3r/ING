
/**
 *	Include Header
 */
#include "Object.h"



 /**
  *	Include Debug
  */
#include <ING/_Debug/Debug.h>



/**
 *	Include Namespace
 */
#include <ING/Reflection/Namespace/Namespace.h>



/**
 *	Include Type
 */
#include <ING/Reflection/Type/Type.h>



/**
 *	Include Class
 */
#include <ING/Reflection/Class/Class.h>



/**
 *	Include Object Function
 */
#include <ING/Reflection/Object/Function/Function.h>



/**
 *	Include Object Procedure
 */
#include <ING/Reflection/Object/Procedure/Procedure.h>



/**
 *	Include Context
 */
#include <ING/Reflection/Context/Context.h>



namespace ING {

	namespace Reflection {

		/**
		 *	Constructors And Destructor
		 */
		C_Object::C_Object(IClass* _class) :
			ING::IObject(),
			_class(_class)
		{

			if (_class->GetNamespace() == _class->GetNamespace()->GetContext()->GetGlobalNamespace()) {

				classFullName = _class->GetName();

			}
			else {

				Namespace* _namespace = _class->GetNamespace();

				while (_namespace != _namespace->GetContext()->GetGlobalNamespace()) {

					classFullName += _namespace->GetName() + "::";

					_namespace = _namespace->GetParent();

				}

				classFullName += _class->GetName();

			}

			context = _class->GetContext();

			LoadProcedures();
			LoadFunctions();

		}

		C_Object::~C_Object() {



		}



		/**
		 *	Release Methods
		 */
		void C_Object::Release() {

			UnloadFunctions();

			UnloadProcedures();

			delete this;
		}



		/**
		 *	Methods
		 */
		void* C_Object::GetPropertyPointer(const String& name) {

			return ((char*)this) + _class->GetMember(name).offsetInBytes;

		}

		void C_Object::UpdateClass() {

			_class = context->GetClass(classFullName);

		}

		void C_Object::LoadProcedures() {

			for (auto item : _class->GetName2MemberMap()) {

				if (item.second.memberType == 2) {

					if (name2Procedure.find(item.second.name) != name2Procedure.end()) {

						name2Procedure[item.second.name]->Release();

					}

					name2Procedure[item.second.name] = item.second.procedureCreator(this);

				}

			}

		}

		void C_Object::UnloadProcedures() {

			for (auto item : name2Procedure) {

				item.second->Release();

			}

		}

		void C_Object::LoadFunctions() {

			for (auto item : _class->GetName2MemberMap()) {

				if (item.second.memberType == 1) {

					if (name2Function.find(item.second.name) != name2Function.end()) {

						name2Function[item.second.name]->Release();

					}

					name2Function[item.second.name] = item.second.functionCreator(this);

				}

			}

		}

		void C_Object::UnloadFunctions() {

			for (auto item : name2Function) {

				item.second->Release();

			}

		}

	}

}
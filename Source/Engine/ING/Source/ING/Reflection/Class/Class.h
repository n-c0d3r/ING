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
 *	Include Debug
 */
#include <ING\_Debug/Debug.h>



/**
 *	Include Type
 */
#include <ING\Reflection\Type\Type.h>



/**
 *	Include ObjectFunction
 */
#include <ING\Reflection\Object\Function\Function.h>



namespace ING {

	namespace Reflection {

		class Namespace;

		class IObject;

		class IObjectFunction;

		struct ClassMember;



		enum ClassMemberAccess {

			CLASS_MEMBER_ACCESS_PRIVATE = 0x0,

			CLASS_MEMBER_ACCESS_PROTECTED = 0x1,

			CLASS_MEMBER_ACCESS_PUBLIC = 0x2

		};



		enum ClassMemberTag {

			CLASS_MEMBER_TAG_EDIT_EVERYWHERE = 0x0,
			CLASS_MEMBER_TAG_NO_EDIT = 0x0

		};



		struct ClassMember {

			bool				isProperty = true;

			size_t				offsetInBytes = 0;

			String				typeName;

			IObjectFunction*		(*functionCreator)(IObject* object);

			String				name = "";

			ClassMemberAccess	access;

			ClassMemberTag		tag;



			bool IsNull() {

				return name == "";

			}



			/**
			 *	To Use With Macros
			 */
			ClassMember& ACCESS (ClassMemberAccess access) {

				this->access = access;

				return *(this);
			}

			ClassMember& TAG(ClassMemberTag tag) {

				this->tag = tag;

				return *(this);
			}

		};



		class ING_API IClass : public IType
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IClass	(const String& name, Namespace* _namespace);
			~IClass	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release() override;



			/**
			 *	Properties
			 */
		private:
			std::unordered_map<String, ClassMember> name2MemberMap;

		public:
			const std::unordered_map<String, ClassMember>& GetName2MemberMap () { return name2MemberMap; }

			bool			IsHasMember(const String& name) { return name2MemberMap.find(name) != name2MemberMap.end(); }

			const ClassMember& GetMember(const String& name) {

				if (!IsHasMember(name)) return {};

				return name2MemberMap[name];
			}

			void			SetMember	(const ClassMember& member){

				name2MemberMap[member.name] = member;
			
			}



			/**
			 *	Methods
			 */
		public:
			virtual IObject* ICreateInstance();

		};



		template<class T>
		class Class : public IClass {

			/**
			 *	Constructors And Destructor
			 */
		public:
			Class(const String& name, Namespace* _namespace) :
				IClass(name, _namespace)
			{



			}

			~Class () {



			}



			/**
			 *	Methods
			 */
		public:
			virtual IObject* ICreateInstance() override;

			template<typename... TArgs>
			T*				 CreateInstance(TArgs... args) {

				if (!IsHasMember("Constructor")) {

					Debug::Error(String(IType::TypeInfoToFullName(typeid(T))) + " Does Not Has Any Constructor");

					return 0;
				}

				T* result = new T(this);

				result->Constructor(args...);

				return result;

			}

		};

		template<class T>
		IObject* Class<T>::ICreateInstance() {

			if (!IsHasMember("Constructor")) {

				Debug::Error(String(IType::TypeInfoToFullName(typeid(T))) + " Does Not Has Any Constructor");

				return 0;
			}

			T* result = new T(this);

			result->GetFunction("Constructor")->Invoke();
		
			return result;
		}

	}

}



/**
 *	Define Macros
 */
#define ING_REFLECT_CLASS(ClassFullName, ExtendedClassFullName) \
public:\
	friend class Class<ClassFullName>;\
\
private:\
	ClassFullName(ING::Reflection::IClass* _class);\
	\
	~ClassFullName();\
	\
public:\
	static ING::Reflection::Class<ClassFullName>*	CreateType		(ING::Reflection::Context* context);\
	static void					ReleaseType		(ING::Reflection::Context* context);\
	static ClassFullName*		ICreateInstance	(ING::Reflection::Context* context);\
	template<typename... TArgs>\
	static ClassFullName*		CreateInstance	(ING::Reflection::Context* context, TArgs... args) {\
		return ((ING::Reflection::Class<ClassFullName>*)(context->GetClass(ING::Reflection::IType::TypeInfoToFullName(typeid(ClassFullName)))))->CreateInstance(args...);\
	}\
	\
	static ING::Utils::String	ClassName		();

#define ING_BEGIN_REFLECTED_CLASS(ClassFullName, ExtendedClassFullName) \
ClassFullName::ClassFullName	(ING::Reflection::IClass* _class) : ExtendedClassFullName(_class) {\
\
\
\
}\
\
ClassFullName::~ClassFullName	()  {\
\
\
\
}\
\
ClassFullName*	ClassFullName::ICreateInstance	(ING::Reflection::Context* context) {\
\
	return (ClassFullName*)((ING::Reflection::Class<ClassFullName>*)(context->GetClass(ING::Reflection::IType::TypeInfoToFullName(typeid(ClassFullName)))))->ICreateInstance();\
\
}\
\
ING::Utils::String	ClassFullName::ClassName	() {\
\
	return ING::Reflection::IType::TypeInfoToFullName(typeid(ClassFullName));\
\
}\
\
void ClassFullName::ReleaseType(ING::Reflection::Context * context) {\
\
ING::Utils::String className = ING::Reflection::IType::TypeInfoToFullName(typeid(ClassFullName));\
\
ING::Reflection::IClass* _class = context->GetClass(className);\
_class->Release();\
\
}\
\
ING::Reflection::Class<ClassFullName>* ClassFullName::CreateType(ING::Reflection::Context* context) {\
\
	ING::Utils::String namespaceFullName = ING::Reflection::IType::FullNameToNamespaceName(typeid(ClassFullName).name());\
	ING::Reflection::Namespace* _namespace = context->CreateNamespace(namespaceFullName);\
\
	ING::Utils::String classBaseName = ING::Reflection::IType::FullNameToBaseName(typeid(ClassFullName).name());\
\
	ING::Reflection::Class<ClassFullName>* classType = new ING::Reflection::Class<ClassFullName>(classBaseName, _namespace);\
\
	ING::Reflection::ClassMember currentMember;\
\

#define ING_END_REFLECTED_CLASS() \
	return classType;\
}

#define ING_CLASS_PROPERTY(ClassFullName, MemberBaseName, ...) \
{\
	unsigned int memberOffset = GetMemberOffset(&ClassFullName::##MemberBaseName);\
	String typeName = ING::Reflection::IType::TypeInfoToFullName(typeid(ClassFullName::##MemberBaseName));\
	currentMember = { true, memberOffset, typeName, [](ING::Reflection::IObject* object)->ING::Reflection::IObjectFunction*{return 0;}, #MemberBaseName, ##__VA_ARGS__ };\
	classType->SetMember(currentMember);\
}\
currentMember

#define ING_CLASS_FUNCTION(ClassFullName, MemberBaseName, ...) \
{\
	currentMember = { false, 0, "", [](ING::Reflection::IObject* object)->ING::Reflection::IObjectFunction*{\
			return new ING::Reflection::ObjectFunction<ClassFullName, &ClassFullName::##MemberBaseName,##__VA_ARGS__>((ClassFullName*)object); \
	},\
	#MemberBaseName};\
	classType->SetMember(currentMember);\
}\
currentMember

#define ING_CLASS_CONSTRUCTOR(ClassFullName, ...) \
ING_CLASS_FUNCTION(ClassFullName, Constructor, void, ##__VA_ARGS__)

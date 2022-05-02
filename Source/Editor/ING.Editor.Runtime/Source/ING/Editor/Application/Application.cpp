
/**
 *	Include Header
 */
#include "Application.h"



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include ApplicationWindowManager
 */
#include <ING/Application/WindowManager/WindowManager.h>



/**
 *	Include Window
 */
#include <ING/Window/Window.h>



/**
 *	Include Event
 */
#include <ING/Event/Event.h>



/**
 *	Include GameApplication
 */
#include <ING/Editor/Game/Application/Application.h>



namespace ING {

	namespace Editor {

		/**
		 *	Constructors And Destructor
		 */
		Application::Application(const WString& configPath, const WString& projectPath) :
			IApplication(configPath),

			projectPath(projectPath),

			gameApplication(0)
		{

			Debug::Log("Start Creating Editor Application");

			SetupRootPaths();

			CreateGameApplication();

			Debug::Log("Editor Application Created");

		}

		Application::~Application() {



		}



		/**
		 *	Init, Release Methods
		 */
		bool	Application::Init() {

			Debug::Log("Start Initializing Editor Application");

			if(!IApplication::Init())return false;

			CreateMainWindow();

			if (!InitGameApplication())return false;

			Debug::Log("Finished Initializing Editor Application");

		}
		void	Application::Release() {

			Debug::Log("Start Releasing Editor Application");

			if(gameApplication != 0)
				gameApplication->Release();

			IApplication::Release();

			ING::Engine::GetInstance()->Shutdown();

			Debug::Log("Finished Releasing Editor Application");

		}



		/**
		 *	Methods
		 */
		void	Application::SetupRootPaths() {

			if (!std::filesystem::exists(projectPath)) {

				Debug::Log("Editor Application Config Not Found");

				Release();

				exit(1);

				return;

			}

			Debug::Log("Setup Engine Rootpaths");

			Engine::GetInstance()->SetRootPath(

				L"Editor",

				Engine::GetInstance()->GetRootPath(L"Game")

			);

			Engine::GetInstance()->SetRootPath(

				L"Game",

				projectPath

			);

		}

		void	Application::CreateMainWindow() {

			Debug::Log("Editor MainWindow Created");

			GetWindowManager()->AddWindow(
			
				IWindow::Create({

					1600,

					900,

					L"ING.Editor",

					"ING.Editor.MainWindow",

					true

				})
			
			);

			GetWindowManager()->GetWindow("ING.Editor.MainWindow")->GetEvent("DESTROY")->AddListener([](Event* e) {
				
				Application::GetInstance()->Release();
				
			});

		}

		void Application::CreateGameApplication() {

			gameApplication = new GameApplication(L"Game:/Config.ini");

		}

		bool Application::InitGameApplication() {

			return gameApplication->Init();
		}

		void Application::PlayGame() {



		}

	}

}
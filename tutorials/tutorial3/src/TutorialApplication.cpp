#include "TutorialApplication.h"
 
TutorialApplication::TutorialApplication()
  : mInfoLabel(0)
{
}
 
TutorialApplication::~TutorialApplication()
{
}
 
void TutorialApplication::createScene()
{
	// Create the camera and adjust the clipping planes
  mCamera->setPosition(Ogre::Vector3(0, 100, 500));
  mCamera->lookAt(Ogre::Vector3(0, 0, -500));
  mCamera->setNearClipDistance(.1);
 
  bool infiniteClip =
    mRoot->getRenderSystem()->getCapabilities()->hasCapability(
      Ogre::RSC_INFINITE_FAR_PLANE);
 
  if (infiniteClip)
    mCamera->setFarClipDistance(0);
  else
    mCamera->setFarClipDistance(50000);

  // Create ground
  Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);

  Ogre::MeshManager::getSingleton().createPlane(
    "ground",
    Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
    plane, 1500, 1500, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Z);

  Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
  mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);

  groundEntity->setMaterialName("Examples/Rockwall");
  groundEntity->setCastShadows(false);
 
  // Create lighting
  mSceneMgr->setAmbientLight(Ogre::ColourValue(.2, .2, .2));

  Ogre::Vector3 lightDir(.55, -.3, .75);
  lightDir.normalise();

  Ogre::Light* light = mSceneMgr->createLight("TestLight");
  light->setType(Ogre::Light::LT_DIRECTIONAL);
  light->setDirection(lightDir);
  light->setDiffuseColour(Ogre::ColourValue::White);
  light->setSpecularColour(Ogre::ColourValue(.4, .4, .4));
 
  // Fog
  Ogre::ColourValue fadeColour(.9, .9, .9);
  mWindow->getViewport(0)->setBackgroundColour(fadeColour);
  mSceneMgr->setFog(Ogre::FOG_EXP2, fadeColour, 0.001);

  // Sky Techniques
  mSceneMgr->setSkyBox(true, "SpaceSkyBox", 1000, false);
}
 
void TutorialApplication::createFrameListener()
{
  BaseApplication::createFrameListener();
  mInfoLabel = mTrayMgr->createLabel(OgreBites::TL_TOP, "InfoBar", "", 350);
  mInfoLabel->setCaption("Example Message");

}
 
void TutorialApplication::destroyScene()
{
}
 
bool TutorialApplication::frameRenderingQueued(const Ogre::FrameEvent& fe)
{
  bool ret = BaseApplication::frameRenderingQueued(fe);
 
  return ret;
}
 
 
#if Ogre_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif
 
#ifdef __cplusplus
extern "C" {
#endif
 
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
  INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
  int main(int argc, char *argv[])
#endif
  {
    // Create application object
    TutorialApplication app;
 
    try {
      app.go();
    } catch( Ogre::Exception& e ) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
      MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
      std::cerr << "An exception has occured: " <<
	e.getFullDescription().c_str() << std::endl;
#endif
    }
 
    return 0;
  }
 
#ifdef __cplusplus
}
#endif

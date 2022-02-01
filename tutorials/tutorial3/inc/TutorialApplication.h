#ifndef __TutorialApplication_h_
#define __TutorialApplication_h_
 
#include "BaseApplication.h"
 
class TutorialApplication : public BaseApplication
{
public:
  TutorialApplication();
  virtual ~TutorialApplication();
 
protected:
  virtual void createScene();
  virtual void createFrameListener();
  virtual void destroyScene();
  virtual bool frameRenderingQueued(const Ogre::FrameEvent& fe);
 
private:
 
  OgreBites::Label* mInfoLabel;
 
};
 
#endif // #ifndef __TutorialApplication_h_

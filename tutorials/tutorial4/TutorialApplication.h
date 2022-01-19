#ifndef TUTORIALAPPLICATION_H
#define TUTORIALAPPLICATION_H
 
#include "BaseApplication.h"
 
class TutorialApplication : public BaseApplication
{
public:
  TutorialApplication();
  virtual ~TutorialApplication();
protected:
  virtual void createScene();
  virtual bool frameRenderingQueued(const Ogre::FrameEvent& fe);
private:
  bool processUnbufferedInput(const Ogre::FrameEvent& fe);
};
 
 
#endif /* TUTORIALAPPLICATION_H */
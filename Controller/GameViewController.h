//
//  GameViewController.h
//  iVN
//
//  Created by Johannes Ekberg on 2011-07-22.
//  Copyright 2011 MacaroniCode Software. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ScriptInterpreterDelegate.h"
#import "ChoiceDelegate.h"
#import "SaveLoadDelegate.h"
@class ScriptInterpreter;
@class SoundEngine;
@class Novel;
@class Sprite;
@class TextPaneView;

#define kBufferSize 500 //Same as VNDS's Buffer Size
#define kDefaultsKeyFontSize @"fontSize"
#define kDefaultsKeySoundVolume @"soundVolume"
#define kDefaultsKeyMusicVolume @"musicVolume"

@interface GameViewController : UIViewController <ScriptInterpreterDelegate,ChoiceDelegate,SaveLoadDelegate>
{
	ScriptInterpreter *interpreter;
	SoundEngine *soundEngine;
	Novel *novel;
	
	
	
	UIImageView *backgroundImageView;
	NSMutableArray *spriteViews;
	
	UIWebView *textView;
	UIView *gameView;
	UIView *sidebarView;
	NSInteger lineCount;
	
	CGSize scaleFactor;
	
	CGPoint touchOrigin;
	CGFloat originalOffset;
	BOOL moved, choiceOpen;
	
	AVAudioPlayer *musicPlayer, *soundPlayer;
	
	double fontSize, soundVolume, musicVolume;
	BOOL started;
}

@property (nonatomic, retain) ScriptInterpreter *interpreter;
@property (nonatomic, retain) SoundEngine *soundEngine;
@property (nonatomic, retain) Novel *novel;
@property (nonatomic, retain) IBOutlet UIImageView *backgroundImageView;
@property (nonatomic, retain) NSMutableArray *spriteViews;
@property (nonatomic, retain) IBOutlet UIWebView *textView;
@property (nonatomic, retain) IBOutlet UIView *gameView;
@property (nonatomic, retain) IBOutlet UIView *sidebarView;

- (IBAction)actionMenu:(UIButton *)sender;
- (IBAction)actionSkip;
- (IBAction)actionStopSkipping;
- (IBAction)actionToggleText;
- (IBAction)actionLoad;
- (IBAction)actionSave;
- (void)actionMenuClosed;
- (void)actionExit;

- (void)writeLine:(NSString *)text quickly:(BOOL)quickly;
- (void)updateOffset;
- (void)playSound:(NSString *)filename onMusicChannel:(BOOL)music loops:(NSInteger)loops fromSave:(BOOL)fromSave;
- (void)loadBackground:(NSString *)background fadeTime:(NSTimeInterval)time fromSave:(BOOL)fromSave;
- (void)addSprite:(Sprite *)sprite fadeTime:(NSTimeInterval)time fromSave:(BOOL)fromSave;

@end

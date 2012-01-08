//
//  Novel.h
//  iVN
//
//  Created by Johannes Ekberg on 2011-07-21.
//  Copyright 2011 MacaroniCode Software. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ScriptInterpreterDelegate.h"
@class NovelInfo;
@class State;
@class Settings;
@class Script;
@class Variable;

/**
 * Main Model object for Novels.
 * A Novel object represents a single title, such as Tsukihime or Fate/Stay Night, that has been loaded into the application.
 * 
 * All data that is not functionality-related, such as Title and Icon, is kept in a separate NovelInfo object stored in the 'info' ivar.
 * This class also handles loading of resources and saves, and translation from relative to absolute paths;
 */

@interface Novel : NSObject <ScriptInterpreterDelegate>
{
	NSString *directory, *path;			//Directory all paths are relative to, and an absolute path to there
	NovelInfo *info;					//Holds data that are not relevant to functionality, such as title and icons
	
	NSMutableDictionary *saves;			//Keys are NSNumbers with the save number (-1 = Global), Values are Save objects
	NSMutableDictionary *gvars;			//Global Variables; saved in the global save file for things like "route cleared"-flags
	
	NSMutableDictionary *scripts;		//Script objects for all objects in the novel; keys are NSStrings with self-relative paths
	State *currentState;				//The current State
}

@property (nonatomic, retain) NSString *directory, *path;
@property (nonatomic, retain) NovelInfo *info;

@property (nonatomic, retain) NSMutableDictionary *saves;
@property (nonatomic, retain) NSMutableDictionary *gvars;

@property (nonatomic, retain) NSMutableDictionary *scripts;
@property (nonatomic, retain) State *currentState;

/**
 * Creates a Novel that reads it's data from the specified directory.
 * @param path to the novel's directory, relative to the application bundle
 */
- (id)initWithDirectory:(NSString *)path;

/**
 * "Translates" a path relative to the novel directory, such as "script/main.scr", into an absolute path.
 * 
 * @param relativePath the relative path to translate
 * @return an absolute path to the file the relative path points to
 */
- (NSString *)relativeToAbsolutePath:(NSString *)relativePath;

/**
 * Loads the script for the given name, or throws an exception if it doesn't exist.
 */
- (void)loadScriptWithName:(NSString *)name;

/**
 * Scans both local and global variable sets for a variable with the given name.
 */
- (Variable *)variableForName:(NSString *)name;

@end
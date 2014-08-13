//
//  BRCAppDelegate.h
//  iBurn
//
//  Created by David Chiles on 7/28/14.
//  Copyright (c) 2014 Burning Man Earth. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "HockeySDK.h"
#import "BRCMapViewController.h"
#import "BRCEventsTableViewController.h"


@interface BRCAppDelegate : UIResponder <UIApplicationDelegate, BITHockeyManagerDelegate, UITabBarControllerDelegate>

@property (strong, nonatomic) UIWindow *window;
@property (nonatomic, strong) UITabBarController *tabBarController;

@property (nonatomic, strong) BRCMapViewController *mapViewController;
@property (nonatomic, strong) BRCFilteredTableViewController *artViewController;
@property (nonatomic, strong) BRCFilteredTableViewController *campsViewController;
@property (nonatomic, strong) BRCEventsTableViewController *eventsViewController;

- (void)showTabBarAnimated:(BOOL)animated;

@end

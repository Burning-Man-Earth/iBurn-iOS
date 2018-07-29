//
//  YapDatabaseViewConnection+iBurn.m
//  iBurn
//
//  Created by Chris Ballinger on 2/24/17.
//  Copyright © 2017 Chris Ballinger. All rights reserved.
//

#import "YapDatabaseViewConnection+iBurn.h"

@interface BRCSectionRowChanges()
- (instancetype) initWithSectionChanges:(NSArray<YapDatabaseViewSectionChange *> *)sectionChanges rowChanges:(NSArray<YapDatabaseViewRowChange *> *) rowChanges;
@end

@implementation BRCSectionRowChanges

- (instancetype) initWithSectionChanges:(NSArray<YapDatabaseViewSectionChange *> *)sectionChanges rowChanges:(NSArray<YapDatabaseViewRowChange *> *) rowChanges {
    NSParameterAssert(sectionChanges != nil);
    NSParameterAssert(rowChanges != nil);
    if (self = [super init]) {
        _sectionChanges = sectionChanges;
        _rowChanges = rowChanges;
    }
    return self;
}

@end

@implementation YapDatabaseViewConnection (iBurn)

- (BRCSectionRowChanges*) brc_getSectionRowChangesForNotifications:(NSArray<NSNotification*> *)notifications
                                                      withMappings:(YapDatabaseViewMappings *)mappings {
    NSParameterAssert(notifications != nil);
    NSParameterAssert(mappings != nil);
    NSArray *sc = nil;
    NSArray *rc = nil;
    [self getSectionChanges:&sc rowChanges:&rc forNotifications:notifications withMappings:mappings];
    if (!sc) {
        sc = @[];
    }
    if (!rc) {
        rc = @[];
    }
    BRCSectionRowChanges *src = [[BRCSectionRowChanges alloc] initWithSectionChanges:sc rowChanges:rc];
    return src;
}

@end

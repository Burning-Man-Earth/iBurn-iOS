//
//  BRCUpdateInfo.h
//  iBurn
//
//  Created by Christopher Ballinger on 6/28/15.
//  Copyright (c) 2015 Burning Man Earth. All rights reserved.
//

#import <Mantle/Mantle.h>
#import "BRCDataObject.h"
#import "BRCYapDatabaseObject.h"

typedef NS_ENUM(NSUInteger, BRCUpdateDataType) {
    BRCUpdateDataTypeUnknown,
    BRCUpdateDataTypeArt,
    BRCUpdateDataTypeCamps,
    BRCUpdateDataTypeEvents,
    BRCUpdateDataTypeTiles,
    BRCUpdateDataTypePoints
};

typedef NS_ENUM(NSUInteger, BRCUpdateFetchStatus) {
    BRCUpdateFetchStatusUnknown,
    BRCUpdateFetchStatusFetching,
    BRCUpdateFetchStatusFailed,
    BRCUpdateFetchStatusComplete
};

NS_ASSUME_NONNULL_BEGIN
/** Metadata parsed from update.json */
@interface BRCUpdateInfo : BRCYapDatabaseObject <MTLJSONSerializing>

@property (nonatomic, strong, readonly) NSString *fileName;
@property (nonatomic, strong, readonly) NSDate *lastUpdated;
@property (nonatomic) BRCUpdateDataType dataType;
@property (nonatomic) BRCUpdateFetchStatus fetchStatus;
@property (nonatomic, strong) NSDate *fetchDate;

/** Returns MTLModel subclass for dataType. Not valid for
 * tiles of course. */
- (nullable Class) dataObjectClass;

/** Converts from updates.json keys */
+ (BRCUpdateDataType) dataTypeFromString:(NSString*)dataTypeString;
+ (BRCUpdateDataType) dataTypeForClass:(Class)dataObjectClass;
+ (nullable NSString*) stringFromDataType:(BRCUpdateDataType)dataType;

/** Return yapKey for a subclass of BRCDataObject */
+ (nullable NSString*) yapKeyForClass:(Class)dataObjectClass;
+ (nullable NSString*) yapKeyForDataType:(BRCUpdateDataType)dataType;

@end
NS_ASSUME_NONNULL_END

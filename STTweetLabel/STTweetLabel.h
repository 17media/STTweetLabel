//
//  STTweetLabel.h
//  STTweetLabel
//
//  Created by Sebastien Thiebaud on 09/29/13.
//  Copyright (c) 2013 Sebastien Thiebaud. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, STTweetHotWord) {
    STTweetHandle = 0,
    STTweetHashtag,
    STTweetLink
};

@interface STTweetLabel : UILabel

@property (nonatomic, strong) NSArray *validProtocols;
@property (nonatomic, assign) BOOL leftToRight;
@property (nonatomic, assign) BOOL textSelectable;
@property (nonatomic, strong) UIColor *selectionColor;
@property (nonatomic, copy) void (^detectionBlock)(STTweetHotWord hotWord, NSString *string, NSString *protocol, NSRange range);

- (void)setText:(NSString *)text attributes:(NSDictionary *)attributes detectHotWords:(BOOL)detectHotWords;

/**
 * Set text with attributes and hot words.
 * @param text
 * @param attributes
 * @param hotWords - The hot words for text, can be nil.
 * @param detectHotWords - Whether to detect hot words for text. If hotWords is not nil, detection will be ignore.
 * @return Detected hot words. If hotWords is provided, return hotWords. If hotWords is nil and detectHotWords is NO, return nil.
 */
- (NSMutableArray *)setText:(NSString *)text
                 attributes:(NSDictionary *)attributes
                   hotWords:(NSMutableArray *)hotWords
             detectHotWords:(BOOL)detectHotWords;

- (void)setAttributes:(NSDictionary *)attributes;
- (void)setAttributes:(NSDictionary *)attributes hotWord:(STTweetHotWord)hotWord;

- (NSDictionary *)attributes;
- (NSDictionary *)attributesForHotWord:(STTweetHotWord)hotWord;

- (CGSize)suggestedFrameSizeToFitEntireStringConstrainedToWidth:(CGFloat)width;
- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event;

@end

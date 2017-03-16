//
//  ZDYFontSizeVC.h
//  LXJichengAndDuotaiAndFengzhuang
//
//  Created by xia on 2017/3/16.
//  Copyright © 2017年 cn.bkw. All rights reserved.
//

#import "ZDYMainViewController.h"


typedef void(^UpdataCellRightLableText)(NSString *cellRightLableText);

@interface ZDYFontSizeVC : ZDYMainViewController

/**
 *  修改选择字体过后的cell提示
 */
@property (nonatomic, strong) UpdataCellRightLableText updataCellRightLableText;

@end

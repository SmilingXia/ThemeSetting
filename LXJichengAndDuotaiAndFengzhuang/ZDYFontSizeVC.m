//
//  ZDYFontSizeVC.m
//  LXJichengAndDuotaiAndFengzhuang
//
//  Created by xia on 2017/3/16.
//  Copyright © 2017年 cn.bkw. All rights reserved.
//

#import "ZDYFontSizeVC.h"

@interface ZDYFontSizeVC ()<UITableViewDelegate,UITableViewDataSource>{
    NSArray *fontSzieArray;
}

@property (nonatomic, strong) UITableView *tableView;

@end

@implementation ZDYFontSizeVC

- (void)viewDidLoad {
    [super viewDidLoad];
    [self displayWidthLeftButton:NO andWidthRightButton:NO];
    self.centerTitleLable.text = @"字体大小";
    [self.rightButton setTitle:@"保存" forState:UIControlStateNormal];
    fontSzieArray = @[@"小",@"中(默认)",@"大",@"超大"];
    [self loadSubView];
}

- (void)loadSubView{
    self.tableView = [[UITableView alloc] initWithFrame:CGRectZero style:UITableViewStyleGrouped];
    [self.view addSubview:self.tableView];
    [self.tableView autoPinEdgesToSuperviewEdgesWithInsets:UIEdgeInsetsMake(Bar_View_Heigth, 0, 0, 0)];
    self.tableView.backgroundColor = [UIColor clearColor];
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
}

#pragma mark - tableview的代理方法
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return fontSzieArray.count;
}

- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section{
    return 0.0001;
}

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section{
    return 0.0001;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    UITableViewCell *cell = [[UITableViewCell alloc] init];
    cell.backgroundColor = [UIColor clearColor];
    cell.tag = indexPath.row + 100;
    cell.textLabel.font = [ZDYThemeStyleClass fontOfSize:18.0f];
    cell.textLabel.text = [fontSzieArray objectAtIndex:indexPath.row];
    
    UIImageView *cellRightImage = [[UIImageView alloc] init];
    [cellRightImage setImage:[UIImage imageNamed:@"cellRight_Image_gou@2x"]];
    [cell addSubview:cellRightImage];
    [cellRightImage autoSetDimensionsToSize:CGSizeMake(30, 30)];
    [cellRightImage autoPinEdgeToSuperviewEdge:ALEdgeTrailing withInset:5];
    [cellRightImage autoAlignAxisToSuperviewAxis:ALAxisHorizontal];
    cellRightImage.hidden = [self isCellRightImageHiddenWidthIndexPath:indexPath];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    [ZDYThemeStyleClass themeStyleClass].textFont = indexPath.row + 1;
    [ZDYNotificationCenter updateFontSzie];//更改字体大小
    self.updataCellRightLableText([fontSzieArray objectAtIndex:indexPath.row]);
    [self.tableView reloadData];
}


- (BOOL)isCellRightImageHiddenWidthIndexPath:(NSIndexPath *)indexPath{
    if ([ZDYThemeStyleClass themeStyleClass].textFont == oneTitleLabFontTextFont &&
        indexPath.row + 1 == oneTitleLabFontTextFont) {
        return NO;
    }
    else if ([ZDYThemeStyleClass themeStyleClass].textFont == twoTitleLabFontTextFont &&
             indexPath.row + 1 == twoTitleLabFontTextFont){
        return NO;
    }
    else if ([ZDYThemeStyleClass themeStyleClass].textFont == threeTitleLabFontTextFont &&
             indexPath.row + 1 == threeTitleLabFontTextFont){
        return NO;
    }
    else if ([ZDYThemeStyleClass themeStyleClass].textFont == oversizedTitleLabTextFont &&
             indexPath.row + 1 == oversizedTitleLabTextFont){
        return NO;
    }else{
        return YES;
    }
}


- (void)rightButtonOnclick:(UIButton *)sender{
    NSLog(@"保存");
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}


@end

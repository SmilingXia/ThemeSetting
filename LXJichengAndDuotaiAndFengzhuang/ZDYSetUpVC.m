//
//  ZDYSetUpVC.m
//  LXJichengAndDuotaiAndFengzhuang
//
//  Created by xia on 2017/3/14.
//  Copyright © 2017年 cn.bkw. All rights reserved.
//

#import "ZDYSetUpVC.h"
#import "ZDYFontSizeVC.h"

@interface ZDYSetUpVC ()<UITableViewDelegate,UITableViewDataSource>{
    NSArray *headerArray;
    NSArray *indexPathArray;
}

@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) UILabel *cellRightLable;

@end

@implementation ZDYSetUpVC

- (void)viewDidLoad {
    [super viewDidLoad];
    self.centerTitleLable.text = @"设置";
    [self displayWidthLeftButton:NO andWidthRightButton:YES];
    headerArray = @[@"通用",@"软件设置"];
    indexPathArray = @[@[@"字体大小",@"夜间模式"],@[@"当前版本",@"修改密码",@"意见反馈"]];
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
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    return headerArray.count;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    NSArray *array = [indexPathArray objectAtIndex:section];
    return array.count;
}

- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section{
    return 0.0001;
}

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section{
    return 50.0f;
}

- (UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section{
    UILabel *headerLableView = [[UILabel alloc] init];
    headerLableView.text = [headerArray objectAtIndex:section];
    headerLableView.font = [ZDYThemeStyleClass fontOfSize:18.0f];
    return headerLableView;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    UITableViewCell *cell = [[UITableViewCell alloc] init];
    cell.textLabel.font = [ZDYThemeStyleClass fontOfSize:18.0f];
    cell.textLabel.text = indexPathArray[indexPath.section][indexPath.row];
    cell.backgroundColor = [UIColor clearColor];
    if (indexPath.section == 0) {
        if (indexPath.row == 0) {
            self.cellRightLable = [[UILabel alloc] init];
            [cell addSubview:self.cellRightLable];
            self.cellRightLable.font = [ZDYThemeStyleClass fontOfSize:18.0f];
            UIImageView *cellRightLableImage = [[UIImageView alloc] init];
            [self.cellRightLable addSubview:cellRightLableImage];
            [cellRightLableImage setImage:[UIImage imageNamed:@"cellRightLable_Image@2x"]];
            
            [self.cellRightLable autoPinEdgeToSuperviewEdge:ALEdgeTrailing withInset:5.0f];
            [self.cellRightLable autoAlignAxisToSuperviewAxis:ALAxisHorizontal];
            [self.cellRightLable autoSetDimensionsToSize:CGSizeMake(125.0f, 30.0f)];
            if ([ZDYThemeStyleClass themeStyleClass].fontSizeText == nil) {
                [ZDYThemeStyleClass themeStyleClass].fontSizeText = @"中(默认)";
            }
            self.cellRightLable.text = [ZDYThemeStyleClass themeStyleClass].fontSizeText;
            self.cellRightLable.textAlignment = NSTextAlignmentCenter;
            [cellRightLableImage autoPinEdgeToSuperviewEdge:ALEdgeTrailing];
            [cellRightLableImage autoSetDimensionsToSize:CGSizeMake(30.0f, 30.0f)];
            [cellRightLableImage autoAlignAxisToSuperviewAxis:ALAxisHorizontal];
        }
        else if (indexPath.row == 1){
            UISwitch *kaiguan = [[UISwitch alloc] init];
            [cell addSubview:kaiguan];
            [kaiguan autoPinEdgeToSuperviewEdge:ALEdgeRight withInset:0.0f];
            [kaiguan autoAlignAxisToSuperviewAxis:ALAxisHorizontal];
            [kaiguan autoSetDimension:ALDimensionWidth toSize:60.0f];
            if ([ZDYThemeStyleClass themeStyleClass].isNightMode) {
                kaiguan.on = YES;
            }
            [kaiguan addTarget:self action:@selector(kaiguanOnclick:) forControlEvents:UIControlEventTouchUpInside];
        }
    }
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    if (indexPath.section == 0 && indexPath.row == 0) {
        ZDYFontSizeVC *vc = [[ZDYFontSizeVC alloc] init];
        WEAK_SELF;
        vc.updataCellRightLableText = ^(NSString *cellRightLableText){
            STRONG_SELF;
            [ZDYThemeStyleClass themeStyleClass].fontSizeText = cellRightLableText;
            [strongSelf.tableView reloadData];
        };
        [self presentViewController:vc animated:YES completion:nil];
    }
}


#pragma mark - 开关按钮事件
- (void)kaiguanOnclick:(UISwitch *)sender{
    if (sender.on) {
        //夜间模式开
        [ZDYThemeStyleClass themeStyleClass].navigationBarItemTableTextColor = [UIColor darkGrayColor];
        [ZDYThemeStyleClass themeStyleClass].navigationBarBackgroundColor = [UIColor lightGrayColor];
        [ZDYThemeStyleClass themeStyleClass].viewBackgroundColor = [UIColor grayColor];
        [ZDYThemeStyleClass themeStyleClass].buttonTitleColor = [UIColor grayColor];
        [ZDYThemeStyleClass themeStyleClass].isNightMode = YES;
        [ZDYNotificationCenter updateStyle];//更新夜间模式
    }else{
        //夜间模式关
        [ZDYThemeStyleClass themeStyleClass].navigationBarBackgroundColor = [UIColor orangeColor];
        [ZDYThemeStyleClass themeStyleClass].navigationBarItemTableTextColor = [UIColor blackColor];
        [ZDYThemeStyleClass themeStyleClass].viewBackgroundColor = [UIColor whiteColor];
        [ZDYThemeStyleClass themeStyleClass].buttonTitleColor = [UIColor whiteColor];
        [ZDYThemeStyleClass themeStyleClass].isNightMode = NO;
        [ZDYNotificationCenter updateStyle];//更新夜间模式
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    
}

@end

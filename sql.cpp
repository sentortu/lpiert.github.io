以创建 已创建的info 和 user 为例
sqlite3 user.db

.schema info // 查看表格概况
drop table info ; // 删除表格
.schema info // 查看表格概况，确认删除ok
显示设置
.mode csv 逗号分隔值
column 对齐的列
line 每行一个值
tabs 由tab 分割的值
tcl TCL 列表元素

// 创建表格
create table user(
	ID  integer,
	NAME text,
	AGE  text);
// 插入数据	
insert into user  (ID,AGE,ADRESS)values(1,20,'北京');
// 查询数据
select ID,AGE,ADRESS from user;
// 修改数据
update user set name ='joinjie' while id =1;
// 删除数据
delete from user where id = 1;

// 模糊操作
select *from user where name like 'lp%';

select *from user where name glob 'lp*';

// 修改表名
alter table user rename to information;

// 修改列
alter table information add column adress text;

// 排序 order
asc/desc
select *from information order by asc;

// 约束
not null ：确保某列不能有null 值
default ： 当某列没有指定值时，为该列提供默认值
unique : 确保某列中的所有值时不同的
primary key : 唯一标识数据表中的各行记录
check ： check 约束确保某列中的所有值满足一定条件

create table user(
	ID INT PRIMARY KEY NOT NULL,
	AGE			   INT NOT NULL UNIQUE,
	ADRESS 		   REAL DEFAULT 'shanghai',
	SALARY         REAL CHECK(SALARY > 0)
	);












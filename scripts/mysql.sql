create table people (
	id        int unsigned not null primary key auto_increment,
	firstname varchar(128) not null,
	lastname  varchar(128) not null,
	email     varchar(128) unique,
	username  varchar(40)  unique,
	password  varchar(40),
	role      varchar(30),
	authentication_method varchar(40)
);

create table operations (
    id                     int unsigned not null primary key auto_increment,
    logtime                datetime     not null unique,
    weather_temperature    smallint,
    weather_conditions     varchar(64),
    weather_precipitation  decimal(4, 1),

    turbidity_raw          decimal(4, 1),
    turbidity_basin        decimal(4, 1),
    turbidity_filter       decimal(4, 1),
    turbidity_finish       decimal(4, 2),

    chlorine_basin_free    decimal(4, 1),
    chlorine_basin_total   decimal(4, 1),
    chlorine_prefilt_free  decimal(4, 1),
    chlorine_prefilt_total decimal(4, 1),
    chlorine_filter_free   decimal(4, 1),
    chlorine_filter_total  decimal(4, 1),
    chlorine_bfilt_free    decimal(4, 1),
    chlorine_bfilt_total   decimal(4, 1),
    chlorine_clrwll_free   decimal(4, 1),
    chlorine_clrwll_total  decimal(4, 1),
    chlorine_finish_free   decimal(4, 1),
    chlorine_finish_total  decimal(4, 1),

    ph_raw                 decimal(4, 1),
    ph_basin               decimal(4, 1),
    ph_filter              decimal(4, 1),
    ph_bfilt               decimal(4, 1),
    ph_clrwll              decimal(4, 1),
    ph_finish              decimal(4, 1),

    temperature_raw        smallint,
    temperature_basin      smallint,
    temperature_filter     smallint,
    temperature_bfilt      smallint,
    temperature_clrwll     smallint,
    temperature_finish     smallint,

    fluoride_finish        decimal(4, 2),
    hardness_raw           smallint unsigned,
    hardness_finish        smallint unsigned,
    alkalinity_raw         smallint unsigned,
    alkalinity_finish      smallint unsigned,
    odor_raw               decimal(6, 1),
    odor_finish            decimal(6, 1),
    chloride_raw           decimal(6, 1),
    chloride_finish        decimal(6, 1),

    stability              decimal(6, 1),
    uv_254_raw             decimal(4, 3),
    uv_254_box             decimal(4, 3),
    uv_254_finish          decimal(4, 3),
    bench_ntu              decimal(3, 2),

    comments               varchar(128)
);

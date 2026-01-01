#include<iostream>
#define INF 1e9  



GraphStructure<string> metroRoutes() {
    int total_stations = 104;
    string station_names[] = {
    "GULBERG", "KARAL_CHOWK", "GANGAL", "FAZIA", "KHANA_PULL", "ZIA_MASJID", "KURI_ROAD", "IQBAL_TOWN", "SOHAN", "FAIZABAD_1",
    "PARADE_GROUND_I8", "SHAKARPARIYAN", "G8", "PIMS_HOSPITAL", "PIMS", "SECRETARIAT", "SHAHEED-E-MILLAT", "7TH_AVENUE", "STOCK_EXCHANGE",
    "KATCHERY", "ISN-E-SINA", "CHAMAN", "KASHMIR_HIGHWAY", "FAIZ_AHMAD_FAIZ", "KHAYABAN-E-JOHAR", "POTOHAR", "IJP_ROAD", "FAIZABAD",
    "SHAMSABAD", "6TH_ROAD", "REHMANABAD", "CHANDNI_CHOWK", "WARIS_KHAN", "COMMITTEE_CHOWK", "LIAQUAT_BAGH", "MARRIR_CHOWK", "SADDAR",
    "AIRPORT", "N5", "GOLRA_MOR", "G13", "NUST", "POLICE_FOUNDATION", "G10", "NHA", "CDA", "AABPARA", "FOREIGN_OFFICE", "LAKE_VIEW_PARK",
    "MALPUR", "SHANDARA_KORANG", "BHARAKAHU", "PARADE_GROUND", "MEHRABADI", "G11_MARKAZ", "INSTITUTE_OF_MODERN_STUDIES", "G10_G11", 
    "TANKI", "G10_MARKAZ", "COLLEGE_MORH", "POLICE_FLATS", "G9_MARKAZ", "KARACHI_COMPANY", "DEVELOPMENT_PARK", "G8_MARKAZ", "DENTAL_HOSPITAL", 
    "NORI_HOSPITAL", "CHILDREN_HOSPITAL_1", "CHILDREN_HOSPITAL", "RESCUE_15", "BANK_COLONY", "SITARA_MARKET", "PULLY_STOP", "IQBAL_HALL", 
    "G6_1", "MELODY_MARKET", "ABPARA_MARKET", "METROPOLITAN_CORPORATION", "NADRA_CHOWK", "SUKH_CHAYN_PARK", "MINISTRY_OF_FOREIGN_AFFAIRS", 
    "RADIO_PAKISTAN", "NATIONAL_LIBRARY", "DIPLOMATIC_ENCLAVE_GATE_4", "AIWAN_E_SADAR_COLONY", "BARI_IMAM", "F8_MARKAZ", "F9_PARK", "SHAHEEN_CHOWK", 
    "BAHRIA_UNIVERSITY", "ZAFAR_CHOWK", "FAISAL_MASJID", "PARVEEN_SHAKIR_ROAD", "KOHSAR", "F7_MARKAZ", "MARGALLA_COLLEGE", "DAMAN_E_KOH", 
    "SAIDPUR", "HILL_ROAD_PARK", "F6_MARKAZ", "MOTAMAR_OFFICE", "MARRIOT_HOTEL", "CABINET_SECRETARIAT", "SUPREME_COURT"
};

    GraphStructure<string> graph(total_stations, station_names);

    // Blue Lines Routes
    graph.addPredefinedConnection(0, "KARAL_CHOWK", 1.0);
    graph.addPredefinedConnection(1, "GANGAL", 1.0);
    graph.addPredefinedConnection(2, "FAZIA", 1.0);
    graph.addPredefinedConnection(3, "KHANA_PULL", 1.0);
    graph.addPredefinedConnection(4, "ZIA_MASJID", 1.0);
    graph.addPredefinedConnection(5, "KURI_ROAD", 1.0);
    graph.addPredefinedConnection(6, "IQBAL_TOWN", 1.0);
    graph.addPredefinedConnection(7, "SOHAN", 1.0);
    graph.addPredefinedConnection(8, "FAIZABAD_1", 1.0);
    graph.addPredefinedConnection(9,"PARADE_GROUND_I8", 1.0);
    graph.addPredefinedConnection(10,"SHAKARPARIYAN", 1.0);
    graph.addPredefinedConnection(11,"G8", 1.0);
    graph.addPredefinedConnection(12,"PIMS_HOSPITAL", 1.0);
    graph.addPredefinedConnection(13,"PIMS", 1.0);

    // Red Lines Routes:
    graph.addPredefinedConnection(14, "KATCHERY", 1.0);
    graph.addPredefinedConnection(15, "PARADE_GROUND ", 1.0);
    graph.addPredefinedConnection(52,"SHAHEED-E-MILLAT",1.0);
    graph.addPredefinedConnection(52,"SECRETARIAT",1.0);
    graph.addPredefinedConnection(17, "SHAHEED-E-MILLAT", 1.0);
    graph.addPredefinedConnection(18, "7TH_AVENUE", 1.0);
    graph.addPredefinedConnection(14, "STOCK_EXCHANGE", 1.0);
    graph.addPredefinedConnection(19, "ISN-E-SINA", 1.0);
    graph.addPredefinedConnection(20, "CHAMAN", 1.0);
    graph.addPredefinedConnection(21, "KASHMIR_HIGHWAY", 1.0);
    graph.addPredefinedConnection(22, "FAIZ_AHMAD_FAIZ", 1.0);
    graph.addPredefinedConnection(23, "KHAYABAN-E-JOHAR", 1.0);
    graph.addPredefinedConnection(24, "POTOHAR", 1.0);
    graph.addPredefinedConnection(25, "IJP_ROAD", 1.0);
    graph.addPredefinedConnection(26, "FAIZABAD", 1.0);
    graph.addPredefinedConnection(27, "SHAMSABAD", 1.0);
    graph.addPredefinedConnection(28, "6TH_ROAD", 1.0);
    graph.addPredefinedConnection(29, "REHMANABAD", 1.0);
    graph.addPredefinedConnection(30, "CHANDNI_CHOWK", 1.0);
    graph.addPredefinedConnection(31, "WARIS_KHAN", 1.0);
    graph.addPredefinedConnection(32, "COMMITTEE_CHOWK", 1.0);
    graph.addPredefinedConnection(33, "LIAQUAT_BAGH", 1.0);
    graph.addPredefinedConnection(34, "MARRIR_CHOWK", 1.0);
    graph.addPredefinedConnection(35, "SADDAR", 1.0);


    // Yellow Lines Paths
    graph.addPredefinedConnection(37,"N5",1.0);
    graph.addPredefinedConnection(38,"GOLRA_MOR",1.0);
    graph.addPredefinedConnection(39,"G13",1.0);
    graph.addPredefinedConnection(40,"NUST",1.0);
    graph.addPredefinedConnection(41,"POLICE_FOUNDATION",1.0);
    graph.addPredefinedConnection(42,"G10",1.0);
    graph.addPredefinedConnection(43,"NHA",1.0);
    graph.addPredefinedConnection(23,"NHA",1.0);

   // Green LINES PATHS:
   graph.addPredefinedConnection(51,"SHANDARA_KORANG",1.0);
   graph.addPredefinedConnection(50,"MALPUR",1.0);
   graph.addPredefinedConnection(49,"LAKE_VIEW_PARK",1.0);
   graph.addPredefinedConnection(48,"FOREIGN_OFFICE",1.0);
   graph.addPredefinedConnection(47,"AABPARA",1.0);
   graph.addPredefinedConnection(46,"CDA",1.0);
   graph.addPredefinedConnection(45,"G8",1.0);
   graph.addPredefinedConnection(12,"CDA",1.0);


   //FR4 PATH
   graph.addPredefinedConnection(41,"MEHRABAD",1.0);
   graph.addPredefinedConnection(53,"G11_MARKAZ",1.0);
   graph.addPredefinedConnection(54,"INSTITUTE_OF_MODERN_STUDIES",1.0);
   graph.addPredefinedConnection(55,"G10_G11",1.0);
   graph.addPredefinedConnection(56,"TANKI",1.0);
   graph.addPredefinedConnection(57,"G10_MARKAZ",1.0);
   graph.addPredefinedConnection(58,"COLLEGE_MORH",1.0);
   graph.addPredefinedConnection(59,"POLICE_FLATS",1.0);
   graph.addPredefinedConnection(60,"G9_MARKAZ",1.0);
   graph.addPredefinedConnection(61,"KARACHI_COMPANY",1.0);
   graph.addPredefinedConnection(21,"KARACHI_COMPANY",1.0);
   graph.addPredefinedConnection(62,"CHAMAN",1.0);
   graph.addPredefinedConnection(21,"DEVELOPMENT_PARK",1.0);
   graph.addPredefinedConnection(63,"G8_MARKAZ",1.0);
   graph.addPredefinedConnection(64,"DENTAL_HOSPITAL",1.0);
   graph.addPredefinedConnection(65,"NORI_HOSPITAL",1.0);
   graph.addPredefinedConnection(66,"CHILDREN_HOSPITAL_1",1.0);
   graph.addPredefinedConnection(13,"CHILDREN_HOSPITAL_1",1.0);

   //FR4 PATH
   graph.addPredefinedConnection(13,"CHILDREN_HOSPITAL",1.0);
   graph.addPredefinedConnection(68,"RESCUE_15",1.0);
   graph.addPredefinedConnection(69,"BANK_COLONY",1.0);
   graph.addPredefinedConnection(70,"SITARA_MARKET",1.0);
   graph.addPredefinedConnection(71,"PULLY_STOP",1.0);
   graph.addPredefinedConnection(72,"IQBAL_HALL",1.0);
   graph.addPredefinedConnection(73,"G6_1",1.0);
   graph.addPredefinedConnection(74,"MELODY_MARKET",1.0);
   graph.addPredefinedConnection(75,"ABPARA_MARKET",1.0);
   graph.addPredefinedConnection(76,"METROPOLITAN_CORPORATION",1.0);
   graph.addPredefinedConnection(77,"NADRA_CHOWK",1.0);
   graph.addPredefinedConnection(78,"SUKH_CHAYN_PARK",1.0);
   graph.addPredefinedConnection(79,"MINISTRY_OF_FOREIGN_AFFAIRS",1.0);
   graph.addPredefinedConnection(80,"RADIO_PAKISTAN",1.0);
   graph.addPredefinedConnection(81,"NATIONAL_LIBRARY",1.0);
   graph.addPredefinedConnection(82,"DIPLOMATIC_ENCLAVE_GATE_4",1.0);
   graph.addPredefinedConnection(83,"AIWAN_E_SADAR_COLONY",1.0);
   graph.addPredefinedConnection(84,"BARI_IMAM",1.0);

   //FR3
   graph.addPredefinedConnection(19,"F8_MARKAZ",1.0);
   graph.addPredefinedConnection(86,"F9_PARK",1.0);
   graph.addPredefinedConnection(87,"SHAHEEN_CHOWK",1.0);
   graph.addPredefinedConnection(88,"BAHRIA_UNIVERSITY",1.0);
   graph.addPredefinedConnection(89,"ZAFAR_CHOWK",1.0);
   graph.addPredefinedConnection(90,"FAISAL_MASJID",1.0);
   graph.addPredefinedConnection(91,"PARVEEN_SHAKIR_ROAD",1.0);
   graph.addPredefinedConnection(92,"KOHSAR",1.0);
   graph.addPredefinedConnection(93,"F7_MARKAZ",1.0);
   graph.addPredefinedConnection(94,"MARGALLA_COLLEGE",1.0);
   graph.addPredefinedConnection(95,"DAMAN_E_KOH",1.0);
   graph.addPredefinedConnection(96,"SAIDPUR",1.0);
   graph.addPredefinedConnection(97,"HILL_ROAD_PARK",1.0);
   graph.addPredefinedConnection(98,"F6_MARKAZ",1.0);
   graph.addPredefinedConnection(99,"MOTAMAR_OFFICE",1.0);
   graph.addPredefinedConnection(100,"MARRIOT_HOTEL",1.0);
   graph.addPredefinedConnection(101,"SECRETARIAT",1.0);
   graph.addPredefinedConnection(15,"CABINET_SECRETARIAT",1.0);
   graph.addPredefinedConnection(102,"SUPREME_COURT",1.0);
   graph.addPredefinedConnection(82,"SUPREME_COURT",1.0);




    return graph;
}

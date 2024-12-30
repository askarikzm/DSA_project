#include<iostream>
#define INF 1e9  



GraphStructure<string> metroRoutes() {
    int total_stations = 55;
    string station_names[] = {
        "GULBERG", "KARAL_CHOWK", "GANGAL", "FAZIA", "KHANA_PULL", "ZIA_MASJID", "KURI_ROAD", "IQBAL_TOWN", "SOHAN", "FAIZABAD_1",
        "PARADE_GROUND_I8", "SHAKARPARIYAN", "G8", "PIMS_HOSPITAL", "PIMS", "SECRETARIAT", "SHAHEED-E-MILLAT", "7TH_AVENUE", "STOCK_EXCHANGE",
        "KATCHERY", "ISN-E-SINA", "CHAMAN", "KASHMIR_HIGHWAY", "FAIZ_AHMAD_FAIZ", "KHAYABAN-E-JOHAR", "POTOHAR", "IJP_ROAD", "FAIZABAD",
        "SHAMSABAD", "6TH_ROAD", "REHMANABAD", "CHANDNI_CHOWK", "WARIS_KHAN", "COMMITTEE_CHOWK", "LIAQUAT_BAGH", "MARRIR_CHOWK", "SADDAR",
        "AIRPORT", "N5", "GOLRA_MOR", "G13", "NUST", "POLICE_FOUNDATION", "G10", "NHA", "CDA", "AABPARA", "FOREIGN_OFFICE", "LAKE_VIEW_PARK",
        "MALPUR", "SHANDARA_KORANG", "BHARAKAHU","PARADE_GROUND"
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


    return graph;
}

package com.wily.valenet.routing;

public enum RoutingTable {
    INSTANCE;

    private RoutingMap routingTable;
    RoutingTable(){
        routingTable = new RoutingMap();
    }

    public RoutingMap getRoutingTable() {
        return routingTable;
    }
}

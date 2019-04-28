package com.wily.valenet.resource;

public enum ResourceTable{
    INSTANCE;

    private ResourceMap resourceTable;

    ResourceTable(){
        resourceTable = new ResourceMap();
    }

    public ResourceMap getResourceTable() {
        return resourceTable;
    }
}

package com.wily.valenet.resource;

import java.util.HashMap;
import java.util.Map;

public class ResourceMap {
    private Map<byte[],Resource> resourceMap= new HashMap<byte[],Resource>();

    public Resource getResouce(byte[] resourceId){
        return resourceMap.get(resourceId);
    }

    public void addResource(byte[] resourceId,Resource resource){
        resourceMap.put(resourceId,resource);
    }
}


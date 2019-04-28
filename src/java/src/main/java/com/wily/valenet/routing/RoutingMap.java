package com.wily.valenet.routing;

import com.wily.valenet.KadUtil;
import com.wily.valenet.NodeId;

import java.util.List;
import java.util.Map;

public class RoutingMap {
    private Map<byte[], List<String>> KBucket;

    public List<String> getNearLeastNode(byte[] nodeId){
        return getNode(KadUtil.OXR(nodeId, NodeId.INSTANCE.getNodeId()));
    }

    public List<String> getNode(byte[] nearNodeId){
        return KBucket.get(nearNodeId);
    }
}

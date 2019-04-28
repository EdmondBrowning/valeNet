package com.wily.valenet;

public enum NodeId {
    INSTANCE;

    private byte[] nodeId;

    NodeId(){
        nodeId = KadUtil.createNodeId();
    }

    public byte[] getNodeId(){
        return nodeId;
    }

}

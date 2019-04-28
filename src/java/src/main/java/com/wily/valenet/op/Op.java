package com.wily.valenet.op;

import com.wily.valenet.resource.Resource;

public class Op {
    private OpType opType;
    private byte[] key;
    private Resource value;

    public Op(OpType opType, byte[] key, Resource value){
        setOpType(opType);
        setKey(key);
        setValue(value);
    }

    public void setKey(byte[] key) {
        this.key = key;
    }

    public void setOpType(OpType opType) {
        this.opType = opType;
    }

    public void setValue(Resource value) {
        this.value = value;
    }

    public byte[] getKey() {
        return key;
    }

    public OpType getOpType() {
        return opType;
    }

    public Resource getValue() {
        return value;
    }
}

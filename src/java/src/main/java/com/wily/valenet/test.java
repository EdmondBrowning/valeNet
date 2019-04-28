package com.wily.valenet;

import org.apache.commons.codec.digest.DigestUtils;

import java.net.SocketException;
import java.net.UnknownHostException;

public class test {
    public static void main(String[] args) throws SocketException, UnknownHostException {
        byte[] bytes = DigestUtils.sha1(KadUtil.getLocalMacAddress());
    }
}

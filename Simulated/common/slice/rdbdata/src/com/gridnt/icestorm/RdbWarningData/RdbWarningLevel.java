// **********************************************************************
//
// Copyright (c) 2003-2017 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.6.4
//
// <auto-generated>
//
// Generated from file `rdbdata.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

package com.gridnt.icestorm.RdbWarningData;

public enum RdbWarningLevel implements java.io.Serializable
{
    
    Critical(0),
    
    Major(1),
    
    Minor(2),
    
    Info(3);

    public int
    value()
    {
        return __value;
    }

    public static RdbWarningLevel
    valueOf(int __v)
    {
        switch(__v)
        {
        case 0:
            return Critical;
        case 1:
            return Major;
        case 2:
            return Minor;
        case 3:
            return Info;
        }
        return null;
    }

    private
    RdbWarningLevel(int __v)
    {
        __value = __v;
    }

    public void
    __write(IceInternal.BasicStream __os)
    {
        __os.writeEnum(value(), 3);
    }

    public static void
    __write(IceInternal.BasicStream __os, RdbWarningLevel __v)
    {
        if(__v == null)
        {
            __os.writeEnum(com.gridnt.icestorm.RdbWarningData.RdbWarningLevel.Critical.value(), 3);
        }
        else
        {
            __os.writeEnum(__v.value(), 3);
        }
    }

    public static RdbWarningLevel
    __read(IceInternal.BasicStream __is)
    {
        int __v = __is.readEnum(3);
        return __validate(__v);
    }

    private static RdbWarningLevel
    __validate(int __v)
    {
        final RdbWarningLevel __e = valueOf(__v);
        if(__e == null)
        {
            throw new Ice.MarshalException("enumerator value " + __v + " is out of range");
        }
        return __e;
    }

    private final int __value;
}
// Decompiled by Jad v1.5.8e. Copyright 2001 Pavel Kouznetsov.
// Jad home page: http://www.geocities.com/kpdus/jad.html
// Decompiler options: packimports(3) 
// Source File Name:   cxExtFileFilter.java

import java.io.File;
import java.util.Hashtable;
import javax.swing.filechooser.FileFilter;

public class cxExtFileFilter extends FileFilter
{

    public cxExtFileFilter()
    {
        filters = null;
        description = null;
        filters = new Hashtable();
    }

    public cxExtFileFilter(String extension, String description)
    {
        this();
        if(extension != null)
            addExtension(extension);
        if(description != null)
            setDescription(description);
    }

    public cxExtFileFilter(String filters[], String description)
    {
        this();
        for(int i = 0; i < filters.length; i++)
            addExtension(filters[i]);

        if(description != null)
            setDescription(description);
    }

    public boolean accept(File f)
    {
        if(f != null)
        {
            if(f.isDirectory())
                return true;
            String extension = getExtension(f);
            if(extension != null && filters.get(getExtension(f)) != null)
                return true;
        }
        return false;
    }

    public String getExtension(File f)
    {
        if(f != null)
        {
            String filename = f.getName();
            int i = filename.lastIndexOf('.');
            if(i > 0 && i < filename.length() - 1)
                return filename.substring(i + 1).toLowerCase();
        }
        return null;
    }

    public void addExtension(String extension)
    {
        if(filters == null)
            filters = new Hashtable(5);
        filters.put(extension.toLowerCase(), this);
    }

    public void setDescription(String description)
    {
        this.description = description;
    }

    public String getDescription()
    {
        return description;
    }

    private Hashtable filters;
    private String description;
}

eturn false;
    }

    return true;
}

// Perform a keyword search
function PerformSearch()
{
    var xmlHttp = GetXmlHttpRequest(), now = new Date();

    if(xmlHttp == null)
    {
        divSearchResults.innerHTML = "<b>XML HTTP request not supported!</b>";
        return;
    }

    divSearchResults.innerHTML = "<span class=\"PaddedText\">Searching...</span>";

    // Add a unique hash to ensure it doesn't use cached results
    xmlHttp.open("GET", "SearchHelp.aspx?Keywords=" + txtSearchText.value +
        "&SortByTitle=" + (chkSortByTitle.checked ? "true" : "false") +
        "&hash=" + now.getTime(), true);

    xmlHttp.onreadystatechange = function()
    {
        if(xmlHttp.readyState == 4)
        {
            divSearchResults.innerHTML = xmlHttp.responseText;

            lastSearchNode = divSearchResults.childNodes[0].childNodes[1];

            if(lastSearchNode != null)
            {
                if(lastSearchNode.tagName != "A")
                    lastSearchNode = lastSearchNode.nextSibling;

                SelectSearchNode(lastSearchNode);
                topicContent.src = lastSearchNode.href;
            }
        }
    }

    xmlHttp.send(null)
}

// Set the style of the specified search result node to "selected"
function SelectSearchNode(node)
{
    if(lastSearchNode != null)
        lastSearchNode.className = "UnselectedNode";

    node.className = "SelectedNode";
    lastSearchNode = node;

    return true;
}

//============================================================================
// KeyWordIndex code

function ShowHideIndex(show)
{
    if(show)
    {
        PopulateIndex(currentIndexPage);

        divNavOpts.style.display = divTree.style.display = "none";
        divIndexOpts.style.display = divIndexResults.style.display = "";
    }
    else
    {
        divIndexOpts.style.display = divIndexResults.style.display = "none";
        divNavOpts.style.display = divTree.style.display = "";
    }
}

// Populate keyword index
function PopulateIndex(startIndex)
{
    var xmlHttp = GetXmlHttpRequest(), now = new Date();
    var firstNode;

    if(xmlHttp == null)
    {
        divIndexResults.innerHTML = "<b>XML HTTP request not supported!</b>";
        return;
    }

    divIndexResults.innerHTML = "<span class=\"PaddedText\">Loading " +
        "keyword index...</span>";

    // Add a unique hash to ensure it doesn't use cached results
    xmlHttp.open("GET", "LoadIndexKeywords.aspx?StartIndex=" + startIndex +
      "&hash=" + now.getTime(), true);

    xmlHttp.onreadystatechange = function()
    {
        if(xmlHttp.readyState == 4)
        {
            divIndexResults.innerHTML = xmlHttp.responseText;

            if(startIndex > 0)
            {
                firstNode = divIndexResults.childNodes[1];

                if(firstNode != null && !firstNode.innerHTML)
                    firstNode = divIndexResults.childNodes[2];
            }
            else
                firstNode = divIndexResults.childNodes[0];

            if(firstNode != null)
                lastIndexNode = firstNode.childNodes[0];

            if(lastIndexNode != null)
            {
                if(lastIndexNode.tagName != "A")
                    lastIndexNode = lastIndexNode.nextSibling;

                SelectIndexNode(lastIndexNode);
                topicContent.src = lastIndexNode.href;
            }

            currentIndexPage = startIndex;
        }
    }

    xmlHttp.send(null)
}

// Set the style of the specified keyword index node to "selected"
function SelectIndexNode(node)
{
    if(lastIndexNode != null)
        lastIndexNode.className = "UnselectedNode";

    node.className = "SelectedNode";
    lastIndexNode = node;

    return true;
}

// Changes the current page with keyword index forward or backward
function ChangeIndexPage(direction)
{
    PopulateIndex(currentIndexPage + direction);

    return false;
}
                                     ﻿<html xmlns:MSHelp="http://msdn.microsoft.com/mshelp"><head><META HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=UTF-8" /><title>Bank Field</title><link rel="stylesheet" type="text/css" href="../styles/presentation.css" /><link rel="stylesheet" type="text/css" href="ms-help://Hx/HxRuntime/HxLink.css" /><script type="text/javascript" src="../scripts/script_prototype.js"> </script><script type="text/javascript" src="../scripts/EventUtilities.js"> </script><script type="text/javascript" src="../scripts/StyleUtilities.js"> </script><script type="text/javascript" src="../scripts/SplitScreen.js"> </script><script type="text/javascript" src="../scripts/ElementCollection.js"> </script><script type="text/javascript" src="../scripts/MemberFilter.js"> </script><script type="text/javascript" src="../scripts/CollapsibleSection.js"> </script><script type="text/javascript" src="../scripts/LanguageFilter.js"> </script><script type="text/javascript" src="../scripts/CookieDataStore.js"> </script><meta name="file" content="1b9363c2-00c0-a3e6-07e1-242d20d65f5d" /><xml xmlns:msxsl="urn:schemas-microsoft-com:xslt"><MSHelp:Attr Name="AssetID" Value="F:ThingMagic.Gen2.BlockWrite.Bank" /><MSHelp:Keyword Index="A" Term="F:ThingMagic.Gen2.BlockWrite.Bank" /><MSHelp:Keyword Index="A" Term="frlrfThingMagicBlockWriteClassBankTopic" /><MSHelp:Keyword Index="K" Term="Bank field" /><MSHelp:Keyword Index="K" Term="Gen2.BlockWrite.Bank field" /><MSHelp:Keyword Index="F" Term="Bank" /><MSHelp:Keyword Index="F" Term="Gen2.BlockWrite.Bank" /><MSHelp:Keyword Index="F" Term="ThingMagic.Gen2.BlockWrite.Bank" /><MSHelp:Attr Name="TopicType" Value="apiref" /><MSHelp:Attr Name="TopicType" Value="kbSyntax" /><MSHelp:Attr Name="APIType" Value="Managed" /><MSHelp:Attr Name="APILocation" Value="MercuryAPI.dll" /><MSHelp:Attr Name="APIName" Value="ThingMagic.BlockWrite.Bank" /><MSHelp:Attr Name="Locale" Value="en-us" /><MSHelp:Attr Name="Abstract" Value="the tag memory bank to write to" /></xml></head><body><div id="control"><span class="productTitle">Mercury API</span><br /><span class="topicTitle">Bank Field</span><br /><div id="toolbar"><span id="chickenFeet"><a href="d4648875-d41a-783b-d5f4-638df39ee413.htm">Namespaces</a> ► <a href="3af3f7df-e311-4e3f-9388-449f848a997b.htm">ThingMagic</a> ► <a href="98910333-e710-6198-8fdc-416f980452fc.htm">Gen2<span class="languageSpecificText"><span class="cs">.</span><span class="vb">.</span><span class="cpp">::</span><span class="nu">.</span></span>BlockWrite</a> ► <span class="selflink">Bank</span></span><span id="languageFilter"><select id="languageSelector" onchange="var names = this.value.split(' '); toggleVisibleLanguage(names[1]); lfc.switchLanguage(names[0]); store.set('lang',this.value); store.save();"><option value="CSharp cs">C#</option><option value="VisualBasic vb">Visual Basic</option><option value="ManagedCPlusPlus cpp">Visual C++</option></select></span></div></div><div id="main"><span style="color: DarkGray"> </span><div class="summary">
            the tag memory bank to write to
            </div><div class="section"><div class="sectionTitle" onclick="toggleSection(this.parentNode)"><img src="../icons/collapse_all.gif" /> Declaration Syntax</div><div class="sectionContent"><div id="syntaxSection"><table class="filter"><tr class="tabs" id="syntaxTabs"><td class="tab" x-lang="CSharp" onclick="toggleClass('syntaxTabs','x-lang','CSharp','activeTab','tab'); toggleStyle('syntaxBlocks','x-lang','CSharp','display','block','none');">C#</td><td class="tab" x-lang="VisualBasic" onclick="toggleClass('syntaxTabs','x-lang','VisualBasic','activeTab','tab'); toggleStyle('syntaxBlocks','x-lang','VisualBasic','display','block','none');">Visual Basic</td><td class="tab" x-lang="ManagedCPlusPlus" onclick="toggleClass('syntaxTabs','x-lang','ManagedCPlusPlus','activeTab','tab'); toggleStyle('syntaxBlocks','x-lang','ManagedCPlusPlus','display','block','none');">Visual C++</td></tr></table><div id="syntaxBlocks"><div class="code" x-lang="CSharp"><pre>
<span class="keyword">public</span> <a href="cb41e589-fa65-fe04-a3f1-1f6175f1ecb2.htm">Gen2<span class="languageSpecificText"><span class="cs">.</span><span class="vb">.</span><span class="cpp">::</span><span class="nu">.</span></span>Bank</a> <span class="identifier">Bank</span></pre></div><div class="code" x-lang="VisualBasic"><pre>
<span class="keyword">Public</span> <span class="identifier">Bank</span> <span class="keyword">As</span> <a href="cb41e589-fa65-fe04-a3f1-1f6175f1ecb2.htm">Gen2<span class="languageSpecificText"><span class="cs">.</span><span class="vb">.</span><span class="cpp">::</span><span class="nu">.</span></span>Bank</a></pre></div><div class="code" x-lang="ManagedCPlusPlus"><pre>
<span class="keyword">public</span>:
<a href="cb41e589-fa65-fe04-a3f1-1f6175f1ecb2.htm">Gen2<span class="languageSpecificText"><span class="cs">.</span><span class="vb">.</span><span class="cpp">::</span><span class="nu">.</span></span>Bank</a> <span class="identifier">Bank</span></pre></div></div></div></div></div><p><div id="footer"><p />Send comments on this topic to
        <a id="HT_MailLink" href="mailto:support%40thingmagic.com?Subject=Mercury API">support@thingmagic.com</a>
        <script type="text/javascript">
        var HT_mailLink = document.getElementById("HT_MailLink");
        var HT_mailLinkText = HT_mailLink.innerHTML;
        HT_mailLink.href += ": " + document.title;
        HT_mailLink.innerHTML = HT_mailLinkText;
        </script> </div>Assembly: <span sdata="assembly">MercuryAPI</span> (Module: MercuryAPI) Version: 1.21.4.61 (1.21.4.61)</p></div></body></html>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              ﻿<html xmlns:MSHelp="http://msdn.microsoft.com/mshelp"><head><META HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=UTF-8" /><title>Gen2.IDS.SL900A.FifoStatus Class</title><link rel="stylesheet" type="text/css" href="../styles/presentation.css" /><link rel="stylesheet" type="text/css" href="ms-help://Hx/HxRuntime/HxLink.css" /><script type="text/javascript" src="../scripts/script_prototype.js"> </script><script type="text/javascript" src="../scripts/EventUtilities.js"> </script><script type="text/javascript" src="../scripts/StyleUtilities.js"> </script><script type="text/javascript" src="../scripts/SplitScreen.js"> </script><script type="text/javascript" src="../scripts/ElementCollection.js"> </script><script type="text/javascript" src="../scripts/MemberFilter.js"> </script><script type="text/javascript" src="../scripts/CollapsibleSection.js"> </script><script type="text/javascript" src="../scripts/LanguageFilter.js"> </script><script type="text/javascript" src="../scripts/CookieDataStore.js"> </script><meta name="file" content="ac125182-579f-098f-6585-0a137bc3803e" /><xml xmlns:msxsl="urn:schemas-microsoft-com:xslt"><MSHelp:Attr Name="AssetID" Value="T:ThingMagic.Gen2.IDS.SL900A.FifoStatus" /><MSHelp:Keyword Index="A" Term="T:ThingMagic.Gen2.IDS.SL900A.FifoStatus" /><MSHelp:Keyword Index="A" Term="frlrfThingMagicFifoStatusClassTopic" /><MSHelp:Keyword Index="A" Term="frlrfThingMagicFifoStatusMembersTopic" /><MSHelp:Keyword Index="K" Term="Gen2.IDS.SL900A.FifoStatus class" /><MSHelp:Keyword Index="K" Term="ThingMagic.Gen2.IDS.SL900A.FifoStatus class" /><MSHelp:Keyword Index="F" Term="Gen2.IDS.SL900A.FifoStatus" /><MSHelp:Keyword Index="F" Term="ThingMagic.Gen2.IDS.SL900A.FifoStatus" /><MSHelp:Attr Name="TopicType" Value="apiref" /><MSHelp:Attr Name="TopicType" Value="kbSyntax" /><MSHelp:Attr Name="APIType" Value="Managed" /><MSHelp:Attr Name="APILocation" Value="MercuryAPI.dll" /><MSHelp:Attr Name="APIName" Value="ThingMagic.FifoStatus" /><MSHelp:Attr Name="Locale" Value="en-us" /><MSHelp:Attr Name="Abstract" Value="FIFO Status return value" /></xml></head><body><div id="control"><span class="productTitle">Mercury API</span><br /><span class="topicTitle">Gen2<span class="languageSpecificText"><span class="cs">.</span><span class="vb">.</span><span class="cpp">::</span><span class="nu">.</span></span>IDS<span class="languageSpecificText"><span class="cs">.</span><span class="vb">.</span><span class="cpp">::</span><span class="nu">.</span></span>SL900A<span class="languageSpecificText"><span class="cs">.</span><span class="vb">.</span><span class="cpp">::</span><span class="nu">.</span></span>FifoStatus Class</span><br /><div id="toolbar"><span id="chickenFeet"><a href="d4648875-d41a-783b-d5f4-638df39ee413.htm">Namespaces</a> ► <a href="3af3f7df-e311-4e3f-9388-449f848a997b.htm">ThingMagic</a> ► <a href="428af195-9ebf-877c-e5fb-c1b254aebe98.htm">Gen2<span class="languageSpecificText"><span class="cs">.</span><span class="vb">.</span><span class="cpp">::</span><span class="nu">.</span></span>IDS<span class="languageSpecificText"><span class="cs">.</span><span class="vb">.</span><span class="cpp">::</span><span class="nu">.</span></span>SL900A</a> ► <span class="selflink">Gen2<span class="languageSpecificText"><span class="cs">.</span><span class="vb">.</span><span class="cpp">::</span><span class="nu">.</span></span>IDS<span class="languageSpecificText"><span class="cs">.</span><span class="vb">.</span><span class="cpp">::</span><span class="nu">.</span></span>SL900A<span class="languageSpecificText"><span class="cs">.</span><span class="vb">.</span><span class="cpp">::</span><span class="nu">.</span></span>FifoStatus</span></span><span id="languageFilter"><select id="languageSelector" onchange="var names = this.value.split(' '); toggleVisibleLanguage(names[1]); lfc.switchLanguage(names[0]); store.set('lang',this.value); store.save();"><option value="CSharp cs">C#</option><option value="VisualBasic vb">Visual Basic</option><option value="ManagedCPlusPlus cpp">Visual C++</option></select></span></div></div><div id="main"><span style="color: DarkGray"> </span><div class="summary">
            FIFO Status return value
            </div><div class="section"><div class="sectionTitle" onclick="toggleSection(this.parentNode)"><img src="../icons/collapse_all.gif" /> Declaration Syntax</div><div class="sectionContent"><div id="syntaxSection"><table class="filter"><tr class="tabs" id="syntaxTabs"><td class="tab" x-lang="CSharp" onclick="toggleClass('syntaxTabs','x-lang','CSharp','activeTab','tab'); toggleStyle('syntaxBlocks','x-lang','CSharp','display','block','none');">C#</td><td class="tab" x-lang="VisualBasic" onclick="toggleClass('syntaxTabs','x-lang','VisualBasic','activeTab','tab'); toggleStyle('syntaxBlocks','x-lang','VisualBasic','display','block','none');">Visual Basic</td><td class="tab" x-lang="ManagedCPlusPlus" onclick="toggleClass('syntaxTabs','x-lang','ManagedCPlusPlus','activeTab','tab'); toggleStyle('syntaxBlocks','x-lang','ManagedCPlusPlus','display','block','none');">Visual C++</td></tr></table><div id="syntaxBlocks"><div class="code" x-lang="CSharp"><pre>
<span class="keyword">public</span> <span class="keyword">class</span> <span class="identifier">FifoStatus</span></pre></div><div class="code" x-lang="VisualBasic"><pre>
<span class="keyword">Public</span> <span class="keyword">Class</span> <span class="identifier">FifoStatus</span></pre></div><div class="code" x-lang="ManagedCPlusPlus"><pre>
<span class="keyword">public</span> <span class="keyword">ref class</span> <span class="identifier">FifoStatus</span></pre></div></div></div></div></div><div class="section"><div class="sectionTitle" onclick="toggleSection(this.parentNode)"><img src="../icons/collapse_all.gif" /> Members</div><div class="sectionContent"><div id="allMembersSection"><table class="filter"><tr class="tabs" id="memberTabs"><td class="tab" value="all" onclick="toggleClass('memberTabs','value','all','activeTab','tab'); processSubgroup('all', 'member'); processList('memberList','filterElement','member');">All Members</td><td class="tab" value="constructor" onclick="toggleClass('memberTabs','value','constructor','activeTab','tab'); processSubgroup('constructor','member');processList('memberList','filterElement','member');">Constructors</td><td class="tab" value="method" onclick="toggleClass('memberTabs','value','method','activeTab','tab'); processSubgroup('method','member'); processList('memberList','filterElement','member');">Methods</td><td class="tab" value="property" onclick="toggleClass('memberTabs','value','property','activeTab','tab'); processSubgroup('property','member'); processList('memberList','filterElement','member');">Properties</td></tr><tr><td class="line" colspan="2"><label for="public"><input id="public" type="checkbox" checked="true" onclick="toggleCheckState('public',this.checked); processList('memberList','filterElement','member');" />Public</label><br /><label for="protected"><input id="protected" type="checkbox" checked="true" onclick="toggleCheckState('protected',this.checked); processList('memberList','filterElement','member');" />Protected</label></td><td class="line" colspan="2"><label for="instance"><input id="instance" type="checkbox" checked="true" onclick="toggleCheckState('instance',this.checked); processList('memberList','filterElement','member');" />Instance</label><br /><label for="static"><input id="static" type="checkbox" checked="true" onclick="toggleCheckState('static',this.checked); processList('memberList','filterElement','member');" />Static</label></td><td class="line" colspan="2"><label for="declared"><input id="declared" type="checkbox" checked="true" onclick="toggleCheckState('declared',this.checked); processList('memberList','filterElement','member');" />Declared</label><br /><label for="inherited"><input id="inherited" type="checkbox" checked="true" onclick="toggleCheckState('inherited',this.checked); processList('memberList','filterElement','member');" />Inherited</label></td></tr></table><table class="members" id="memberList"><tr><th class="iconColumn">Icon</th><th class="nameColumn">Member</th><th class="descriptionColumn">Description</th></tr><tr data="constructor; public; instance; declared"><td><img src="../icons/pubmethod.gif" /></td><td><a href="1526f818-aba1-ed96-d843-513ea8ea9a61.htm">Gen2<span class="languageSpecificText"><span class="cs">.</span><span class="vb">.</span><span class="cpp">::</span><span class="nu">.</span></span>IDS<span class="languageSpecificText"><span class="cs">.</span><span class="vb">.</span><span class="cpp">::</span><span class="nu">.</span></span>SL900A<span class="languageSpecificText"><span class="cs">.</span><span class="vb">.</span><span class="cpp">::</span><span class="nu">.</span></span>FifoStatus(Byte)</a></td><td><div class="summary">
            Create FifoStatus object from AccessFifo Status return value
            </div><br /></td></tr><tr data="constructor; public; instance; declared"><td><img src="../icons/pubmethod.gif" /></td><td><a href="4413514c-3159-5670-162e-465bdd81ef9c.htm">Gen2<span class="languageSpecificText"><span class="cs">.</span><span class="vb">.</span><span class="cpp">::</span><span class="nu">.</span></span>IDS<span class="languageSpecificText"><span class="cs">.</span><span class="vb">.</span><span class="cpp">::</span><span class="nu">.</span></span>SL900A<span class="languageSpecificText"><span class="cs">.</span><span class="vb">.</span><span class="cpp">::</span><span class="nu">.</span></span>FifoStatus(<span class="languageSpecificText"><span class="cpp">array&lt;</span></span>Byte<span class="languageSpecificText"><span class="cpp">&gt;</span><span class="cs">[]</span><span class="vb">()</span><span class="nu">[]</span></span>)</a></td><td><div class="summary">
            Create FIFO Status reply object
            </div><br /></td></tr><tr data="property; public; instance; declared"><td><img src="../icons/pubproperty.gif" /></td><td><a href="5b136d4b-05f0-a93b-d80d-b070a99863e5.htm">DataReady</a></td><td><div class="summary">
            Data Ready bit
            </div><br /></td></tr><tr data="method; public; instance; inherited"><td><img src="../icons/pubmethod.gif" /></td><td><a href="http://msdn2.microsoft.com/en-us/library/bsc2ak47" target="_blank">Equals(Object)</a></td><td><div class="summary">
                    Determines whether the specified <a href="http://msdn2.microsoft.com/en-us/library/e5kfa45b" target="_blank">Object</a> is equal to the current <a href="http://msdn2.microsoft.com/en-us/library/e5kfa45b" target="_blank">Object</a>.
                </div> (Inherited from <a href="http://msdn2.microsoft.com/en-us/library/e5kfa45b" target="_blank">Object</a>.)<br /></td></tr><tr data="property; public; instance; declared"><td><img src="../icons/pubproperty.gif" /></td><td><a href="e1d2c1a1-ae40-2d2f-000f-2dd63c462572.htm">FifoBusy</a></td><td><div class="summary">
            FIFO Busy bit
            </div><br /></td></tr><tr data="method; protected; instance; inherited"><td><img src="../icons/protmethod.gif" /></td><td><a href="http://msdn2.microsoft.com/en-us/library/4k87zsw7" target="_blank">Finalize<span class="languageSpecificText"><span class="cs">()</span><span class="cpp">()</span><span class="nu">()</span></span></a></td><td><div class="summary">
                    Allows an <a href="http://msdn2.microsoft.com/en-us/library/e5kfa45b" target="_blank">Object</a> to attempt to free resources and perform other cleanup operations before the <a href="http://msdn2.microsoft.com/en-us/library/e5kfa45b" target="_blank">Object</a> is reclaimed by garbage collection.
                </div> (Inherited from <a href="http://msdn2.microsoft.com/en-us/library/e5kfa45b" target="_blank">Object</a>.)<br /></td></tr><tr data="method; public; instance; inherited"><td><img src="../icons/pubmethod.gif" /></td><td><a href="http://msdn2.microsoft.com/en-us/library/zdee4b3y" target="_blank">GetHashCode<span class="languageSpecificText"><span class="cs">()</span><span class="cpp">()</span><span class="nu">()</span></span></a></td><td><div class="summary">
                    Serves as a hash function for a particular type. 
                </div> (Inherited from <a href="http://msdn2.microsoft.com/en-us/library/e5kfa45b" target="_blank">Object</a>.)<br /></td></tr><tr data="method; public; instance; inherited"><td><img src="../icons/pubmethod.gif" /></td><td><a href="http://msdn2.microsoft.com/en-us/library/dfwy45w9" target="_blank">GetType<span class="languageSpecificText"><span class="cs">()</span><span class="cpp">()</span><span class="nu">()</span></span></a></td><td><div class="summary">
                    Gets the <a href="http://msdn2.microsoft.com/en-us/library/42892f65" target="_blank">Type</a> of the current instance.
                </div> (Inherited from <a href="http://msdn2.microsoft.com/en-us/library/e5kfa45b" target="_blank">Object</a>.)<br /></td></tr><tr data="method; protected; instance; inherited"><td><img src="../icons/protmethod.gif" /></td><td><a href="http://msdn2.microsoft.com/en-us/library/57ctke0a" target="_blank">MemberwiseClone<span class="languageSpecificText"><span class="cs">()</span><span class="cpp">()</span><span class="nu">()</span></span></a></td><td><div class="summary">
                    Creates a shallow copy of the current <a href="http://msdn2.microsoft.com/en-us/library/e5kfa45b" target="_blank">Object</a>.
                </div> (Inherited from <a href="http://msdn2.microsoft.com/en-us/library/e5kfa45b" target="_blank">Object</a>.)<br /></td></tr><tr data="property; public; instance; declared"><td><img src="../icons/pubproperty.gif" /></td><td><a href="ef2416f1-a732-73ec-5a8b-13ad8ae7513e.htm">NoData</a></td><td><div class="summary">
            No Data bit
            </div><br /></td></tr><tr data="property; public; instance; declared"><td><img src="../icons/pubproperty.gif" /></td><td><a href="39da7516-ba27-5b82-af0b-8cb1743982c4.htm">NumValidBytes</a></td><td><div class="summary">
            Number of valid bytes in FIFO register
            </div><br /></td></tr><tr data="property; public; instance; declared"><td><img src="../icons/pubproperty.gif" /></td><td><a href="cc25c591-f25a-b2b7-f331-4d421fd3d3da.htm">Raw</a></td><td><div class="summary">
            Raw 8-bit response from AccessFifo Status command
            </div><br /></td></tr><tr data="property; public; instance; declared"><td><img src="../icons/pubproperty.gif" /></td><td><a href="342d2e15-85e9-ba6a-36ed-96f476169c43.htm">Source</a></td><td><div class="summary">
            Data Source bit (SPI, RFID)
            </div><br /></td></tr><tr data="method; public; instance; declared"><td><img src="../icons/pubmethod.gif" /></td><td><a href="ad63fd08-ca01-ab67-5ca6-717de7384cec.htm">ToString<span class="languageSpecificText"><span class="cs">()</span><span class="cpp">()</span><span class="nu">()</span></span></a></td><td><div class="summary">
            Returns a string that represents the current object.
            </div> (Overrides <a href="http://msdn2.microsoft.com/en-us/library/e5kfa45b" target="_blank">Object</a>.<a href="http://msdn2.microsoft.com/en-us/library/7bxwbwt2" target="_blank">ToString<span class="languageSpecificText"><span class="cs">()</span><span class="cpp">()</span><span class="nu">()</span></span></a>.)<br /></td></tr></table></div></div></div><div class="section"><div class="sectionTitle" onclick="toggleSection(this.parentNode)"><img src="../icons/collapse_all.gif" /> Inheritance Hierarchy</div><div class="sectionContent"><table cellspacing="0" cellpadding="0"><tr><td colspan="2"><a href="http://msdn2.microsoft.com/en-us/library/e5kfa45b" target="_blank">Object</a></td></tr><tr><td><img src="../icons/LastChild.gif" /></td><td><span class="selflink">Gen2<span class="languageSpecificText"><span class="cs">.</span><span class="vb">.</span><span class="cpp">::</span><span class="nu">.</span></span>IDS<span class="languageSpecificText"><span class="cs">.</span><span class="vb">.</span><span class="cpp">::</span><span class="nu">.</span></span>SL900A<span class="languageSpecificText"><span class="cs">.</span><span class="vb">.</span><span class="cpp">::</span><span class="nu">.</span></span>FifoStatus</span></td></tr></table></div></div><p><div id="footer"><p />Send comments on this topic to
        <a id="HT_MailLink" href="mailto:support%40thingmagic.com?Subject=Mercury API">support@thingmagic.com</a>
        <script type="text/javascript">
        var HT_mailLink = document.getElementById("HT_MailLink");
        var HT_mailLinkText = HT_mailLink.innerHTML;
        HT_mailLink.href += ": " + document.title;
        HT_mailLink.innerHTML = HT_mailLinkText;
        </script> </div>Assembly: <span sdata="assembly">MercuryAPI</span> (Module: MercuryAPI) Version: 1.21.4.61 (1.21.4.61)</p></div></body></html>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        ﻿<html xmlns:MSHelp="http://msdn.microsoft.com/mshelp"><head><META HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=UTF-8" /><title>PARAM_ThingMagicIDSSetShelfLife Class</title><link rel="stylesheet" type="text/css" href="../styles/presentation.css" /><link rel="stylesheet" type="text/css" href="ms-help://Hx/HxRuntime/HxLink.css" /><script type="text/javascript" src="../scripts/script_prototype.js"> </script><script type="text/javascript" src="../scripts/EventUtilities.js"> </script><script type="text/javascript" src="../scripts/StyleUtilities.js"> </script><script type="text/javascript" src="../scripts/SplitScreen.js"> </script><script type="text/javascript" src="../scripts/ElementCollection.js"> </script><script type="text/javascript" src="../scripts/MemberFilter.js"> </script><script type="text/javascript" src="../scripts/CollapsibleSection.js"> </script><script type="text/javascript" src="../scripts/LanguageFilter.js"> </script><script type="text/javascript" src="../scripts/CookieDataStore.js"> </script><meta name="file" content="42815ff7-eaa9-ad15-92d9-4ed5d7dae554" /><xml xmlns:msxsl="urn:schemas-microsoft-com:xslt"><MSHelp:Attr Name="AssetID" Value="T:Org.LLRP.LTK.LLRPV1.thingmagic.PARAM_ThingMagicIDSSetShelfLife" /><MSHelp:Keyword Index="A" Term="T:Org.LLRP.LTK.LLRPV1.thingmagic.PARAM_ThingMagicIDSSetShelfLife" /><MSHelp:Keyword Index="A" Term="frlrfOrgLLRPLTKLLRPV1thingmagicPARAM_ThingMagicIDSSetShelfLifeClassTopic" /><MSHelp:Keyword Index="A" Term="frlrfOrgLLRPLTKLLRPV1thingmagicPARAM_ThingMagicIDSSetShelfLifeMembersTopic" /><MSHelp:Keyword Index="K" Term="PARAM_ThingMagicIDSSetShelfLife class" /><MSHelp:Keyword Index="K" Term="Org.LLRP.LTK.LLRPV1.thingmagic.PARAM_ThingMagicIDSSetShelfLife class" /><MSHelp:Keyword Index="F" Term="PARAM_ThingMagicIDSSetShelfLife" /><MSHelp:Keyword Index="F" Term="Org.LLRP.LTK.LLRPV1.thingmagic.PARAM_ThingMagicIDSSetShelfLife" /><MSHelp:Attr Name="TopicType" Value="apiref" /><MSHelp:Attr Name="TopicType" Value="kbSyntax" /><MSHelp:Attr Name="APIType" Value="Managed" /><MSHelp:Attr Name="APILocation" Value="LLRP.dll" /><MSHelp:Attr Name="APIName" Value="Org.LLRP.LTK.LLRPV1.thingmagic.PARAM_ThingMagicIDSSetShelfLife" /><MSHelp:Attr Name="Locale" Value="en-us" /><MSHelp:Attr Name="Abstract" Value="[Missing &lt;summary&gt; documentation for T:Org.LLRP.LTK.LLRPV1.thingmagic.PARAM_ThingMagicIDSSetShelfLife]" /></xml></head><body><div id="control"><span class="productTitle">Mercury API</span><br /><span class="topicTitle">PARAM_ThingMagicIDSSetShelfLife Class</span><br /><div id="toolbar"><span id="chickenFeet"><a href="d4648875-d41a-783b-d5f4-638df39ee413.htm">Namespaces</a> ► <a href="8ff80a0c-797f-94c7-03ae-23332b0ef831.htm">Org.LLRP.LTK.LLRPV1.thingmagic</a> ► <span class="selflink">PARAM_ThingMagicIDSSetShelfLife</span></span><span id="languageFilter"><select id="languageSelector" onchange="var names = this.value.split(' '); toggleVisibleLanguage(names[1]); lfc.switchLanguage(names[0]); store.set('lang',this.value); store.save();"><option value="CSharp cs">C#</option><option value="VisualBasic vb">Visual Basic</option><option value="ManagedCPlusPlus cpp">Visual C++</option></select></span></div></div><div id="main"><span style="color: DarkGray"> </span><div class="summary"><p style="color: #dc143c; font-size: 8.5pt; font-weight: bold;">[Missing &lt;summary&gt; documentation for T:Org.LLRP.LTK.LLRPV1.thingmagic.PARAM_ThingMagicIDSSetShelfLife]</p></div><div class="section"><div class="sectionTitle" onclick="toggleSection(this.parentNode)"><img src="../icons/collapse_all.gif" /> Declaration Syntax</div><div class="sectionContent"><div id="syntaxSection"><table class="filter"><tr class="tabs" id="syntaxTabs"><td class="tab" x-lang="CSharp" onclick="toggleClass('syntaxTabs','x-lang','CSharp','activeTab','tab'); toggleStyle('syntaxBlocks','x-lang','CSharp','display','block','none');">C#</td><td class="tab" x-lang="VisualBasic" onclick="toggleClass('syntaxTabs','x-lang','VisualBasic','activeTab','tab'); toggleStyle('syntaxBlocks','x-lang','VisualBasic','display','block','none');">Visual Basic</td><td class="tab" x-lang="ManagedCPlusPlus" onclick="toggleClass('syntaxTabs','x-lang','ManagedCPlusPlus','activeTab','tab'); toggleStyle('syntaxBlocks','x-lang','ManagedCPlusPlus','display','block','none');">Visual C++</td></tr></table><div id="syntaxBlocks"><div class="code" x-lang="CSharp"><pre>
<span class="keyword">public</span> <span class="keyword">class</span> <span class="identifier">PARAM_ThingMagicIDSSetShelfLife</span> : <a href="c3ab1bce-63f5-b85a-a21f-c6e67df51d3a.htm">PARAM_Custom</a>, 
	<a href="ee5c6bf1-288d-5490-09da-437b7bc7c5cd.htm">IAccessCommandOpSpec_Custom_Param</a>, <a href="7cd3ad15-068c-00df-6397-e43436c06cbe.htm">ICustom_Parameter</a>, <a href="0e2fa05a-e2f7-f03c-8988-b941db1ff38c.htm">IParameter</a></pre></div><div class="code" x-lang="VisualBasic"><pre>
<span class="keyword">Public</span> <span class="keyword">Class</span> <span class="identifier">PARAM_ThingMagicIDSSetShelfLife</span> _
	<span class="keyword">Inherits</span> <a href="c3ab1bce-63f5-b85a-a21f-c6e67df51d3a.htm">PARAM_Custom</a> _
	<span class="keyword">Implements</span> <a href="ee5c6bf1-288d-5490-09da-437b7bc7c5cd.htm">IAccessCommandOpSpec_Custom_Param</a>, <a href="7cd3ad15-068c-00df-6397-e43436c06cbe.htm">ICustom_Parameter</a>, <a href="0e2fa05a-e2f7-f03c-8988-b941db1ff38c.htm">IParameter</a></pre></div><div class="code" x-lang="ManagedCPlusPlus"><pre>
<span class="keyword">public</span> <span class="keyword">ref class</span> <span class="identifier">PARAM_ThingMagicIDSSetShelfLife</span> : <span class="keyword">public</span> <a href="c3ab1bce-63f5-b85a-a21f-c6e67df51d3a.htm">PARAM_Custom</a>, 
	<a href="ee5c6bf1-288d-5490-09da-437b7bc7c5cd.htm">IAccessCommandOpSpec_Custom_Param</a>, <a href="7cd3ad15-068c-00df-6397-e43436c06cbe.htm">ICustom_Parameter</a>, <a href="0e2fa05a-e2f7-f03c-8988-b941db1ff38c.htm">IParameter</a></pre></div></div></div></div></div><div class="section"><div class="sectionTitle" onclick="toggleSection(this.parentNode)"><img src="../icons/collapse_all.gif" /> Members</div><div class="sectionContent"><div id="allMembersSection"><table class="filter"><tr class="tabs" id="memberTabs"><td class="tab" value="all" onclick="toggleClass('memberTabs','value','all','activeTab','tab'); processSubgroup('all', 'member'); processList('memberList','filterElement','member');">All Members</td><td class="tab" value="constructor" onclick="toggleClass('memberTabs','value','constructor','activeTab','tab'); processSubgroup('constructor','member');processList('memberList','filterElement','member');">Constructors</td><td class="tab" value="method" onclick="toggleClass('memberTabs','value','method','activeTab','tab'); processSubgroup('method','member'); processList('memberList','filterElement','member');">Methods</td><td class="tab" value="property" onclick="toggleClass('memberTabs','value','property','activeTab','tab'); processSubgroup('property','member'); processList('memberList','filterElement','member');">Properties</td><td class="tab" value="field" onclick="toggleClass('memberTabs','value','field','activeTab','tab'); processSubgroup('field','member'); processList('memberList','filterElement','member');">Fields</td></tr><tr><td class="line" colspan="2"><label for="public"><input id="public" type="checkbox" checked="true" onclick="toggleCheckState('public',this.checked); processList('memberList','filterElement','member');" />Public</label><br /><label for="protected"><input id="protected" type="checkbox" checked="true" onclick="toggleCheckState('protected',this.checked); processList('memberList','filterElement','member');" />Protected</label></td><td class="line" colspan="2"><label for="instance"><input id="instance" type="checkbox" checked="true" onclick="toggleCheckState('instance',this.checked); processList('memberList','filterElement','member');" />Instance</label><br /><label for="static"><input id="static" type="checkbox" checked="true" onclick="toggleCheckState('static',this.checked); processList('memberList','filterElement','member');" />Static</label></td><td class="line" colspan="2"><label for="declared"><input id="declared" type="checkbox" checked="true" onclick="toggleCheckState('declared',this.checked); processList('memberList','filterElement','member');" />Declared</label><br /><label for="inherited"><input id="inherited" type="checkbox" checked="true" onclick="toggleCheckState('inherited',this.checked); processList('memberList','filterElement','member');" />Inherited</label></td></tr></table><table class="members" id="memberList"><tr><th class="iconColumn">Icon</th><th class="nameColumn">Member</th><th class="descriptionColumn">Description</th></tr><tr data="constructor; public; instance; declared"><td><img src="../icons/pubmethod.gif" /></td><td><a href="f9a9d26b-d85b-24a3-c68d-358d1cba0203.htm">PARAM_ThingMagicIDSSetShelfLife<span class="languageSpecificText"><span class="cs">()</span><span class="cpp">()</span><span class="nu">()</span></span></a></td><td><div class="summary">Initializes a new instance of the <span class="selflink">PARAM_ThingMagicIDSSetShelfLife</span> class</div><br /></td></tr><tr data="method; public; instance; declared"><td><img src="../icons/pubmethod.gif" /></td><td><a href="d21e2b8c-9d06-e432-e939-2528ced62d50.htm">AddCustomParameter(ICustom_Parameter)</a></td><td><br /></td></tr><tr data="field; public; instance; declared"><td><img src="../icons/pubfield.gif" /></td><td><a href="f4f7740f-a25e-c059-0a2a-5e2c628cef8d.htm">Custom</a></td><td><br /></td></tr><tr data="field; protected; instance; inherited"><td><img src="../icons/protfield.gif" /></td><td><a href="3742c34d-ae71-a03c-7d4e-1caa8242ce87.htm">data</a></td><td> (Inherited from <a href="c3ab1bce-63f5-b85a-a21f-c6e67df51d3a.htm">PARAM_Custom</a>.)<br /></td></tr><tr data="method; public; instance; inherited"><td><img src="../icons/pubmethod.gif" /></td><td><a href="http://msdn2.microsoft.com/en-us/library/bsc2ak47" target="_blank">Equals(Object)</a></td><td><div class="summary">
                    Determines whether the specified <a href="http://msdn2.microsoft.com/en-us/library/e5kfa45b" target="_blank">Object</a> is equal to the current <a href="http://msdn2.microsoft.com/en-us/library/e5kfa45b" target="_blank">Object</a>.
                </div> (Inherited from <a href="http://msdn2.microsoft.com/en-us/library/e5kfa45b" target="_blank">Object</a>.)<br /></td></tr><tr data="method; protected; instance; inherited"><td><img src="../icons/protmethod.gif" /></td><td><a href="http://msdn2.microsoft.com/en-us/library/4k87zsw7" target="_blank">Finalize<span class="languageSpecificText"><span class="cs">()</span><span class="cpp">()</span><span class="nu">()</span></span></a></td><td><div class="summary">
                    Allows an <a href="http://msdn2.microsoft.com/en-us/library/e5kfa45b" target="_blank">Object</a> to attempt to free resources and perform other cleanup operations before the <a href="http://msdn2.microsoft.com/en-us/library/e5kfa45b" target="_blank">Object</a> is reclaimed by garbage collection.
                </div> (Inherited from <a href="http://msdn2.microsoft.com/en-us/library/e5kfa45b" target="_blank">Object</a>.)<br /></td></tr><tr data="method; public; static; declared"><td><img src="../icons/pubmethod.gif" /><img src="../icons/static.gif" title="static member" /></td><td><a href="c1dc7eb3-3d8c-a7a6-df83-9f72416c8b6d.htm">FromBitArray(BitArray<span class="languageSpecificText"><span class="cpp">%</span></span>, Int32<span class="languageSpecificText"><span class="cpp">%</span></span>, Int32)</a></td><td><br /></td></tr><tr data="method; public; instance; inherited"><td><img src="../icons/pubmethod.gif" /></td><td><a href="d5fdea3f-923b-25ac-2a05-2416e058569b.htm">FromString(String)</a></td><td> (Inherited from <a href="d7c4efee-cdc5-8530-b097-d1dfcd416833.htm">Parameter</a>.)<br /></td></tr><tr data="method; public; static; declared"><td><img src="../icons/pubmethod.gif" /><img src="../icons/static.gif" title="static member" /></td><td><a href="b3ab0d54-3d45-37fe-344e-96f2a8b16e1d.htm">FromXmlNode(XmlNode)</a></td><td><br /></td></tr><tr data="method; public; instance; inherited"><td><img src="../icons/pubmethod.gif" /></td><td><a href="http://msdn2.microsoft.com/en-us/library/zdee4b3y" target="_blank">GetHashCode<span class="languageSpecificText"><span class="cs">()</span><span class="cpp">()</span><span class="nu">()</span></span></a></td><td><div class="summary">
                    Serves as a hash function for a particular type. 
                </div> (Inherited from <a href="http://msdn2.microsoft.com/en-us/library/e5kfa45b" target="_blank">Object</a>.)<br /></td></tr><tr data="method; public; instance; inherited"><td><img src="../icons/pubmethod.gif" /></td><td><a href="http://msdn2.microsoft.com/en-us/library/dfwy45w9" target="_blank">GetType<span class="languageSpecificText"><span class="cs">()</span><span class="cpp">()</span><span class="nu">()</span></span></a></td><td><div class="summary">
                    Gets the <a href="http://msdn2.microsoft.com/en-us/library/42892f65" target="_blank">Type</a> of the current instance.
                </div> (Inherited from <a href="http://msdn2.microsoft.com/en-us/library/e5kfa45b" target="_blank">Object</a>.)<br /></td></tr><tr data="field; protected; instance; inherited"><td><img src="../icons/protfield.gif" /></td><td><a href="5336b9b0-79ea-7d6c-3112-7faa44365d2a.htm">length</a></td><td> (Inherited from <a href="d7c4efee-cdc5-8530-b097-d1dfcd416833.htm">Parameter</a>.)<br /></td></tr><tr data="property; public; instance; inherited"><td><img src="../icons/pubproperty.gif" /></td><td><a href="4193ee95-5d33-3105-b89c-9b6684e237f1.htm">Length</a></td><td> (Inherited from <a href="d7c4efee-cdc5-8530-b097-d1dfcd416833.htm">Parameter</a>.)<br /></td></tr><tr data="method; protected; instance; inherited"><td><img src="../icons/protmethod.gif" /></td><td><a href="http://msdn2.microsoft.com/en-us/library/57ctke0a" target="_blank">MemberwiseClone<span class="languageSpecificText"><span class="cs">()</span><span class="cpp">()</span><span class="nu">()</span></span></a></td><td><div class="summary">
                    Creates a shallow copy of the current <a href="http://msdn2.microsoft.com/en-us/library/e5kfa45b" target="_blank">Object</a>.
                </div> (Inherited from <a href="http://msdn2.microsoft.com/en-us/library/e5kfa45b" target="_blank">Object</a>.)<br /></td></tr><tr data="field; protected; instance; inherited"><td><img src="../icons/protfield.gif" /></td><td><a href="948caf34-c2d4-6533-8154-65c124679afa.htm">ParameterSubtype</a></td><td> (Inherited from <a href="c3ab1bce-63f5-b85a-a21f-c6e67df51d3a.htm">PARAM_Custom</a>.)<br /></td></tr><tr data="property; public; instance; declared"><td><img src="../icons/pubproperty.gif" /></td><td><a href="752e44e9-634d-ffa0-3c7d-7ae3a3fe424b.htm">SUB_TYPE</a></td><td><br /></td></tr><tr data="property; public; instance; inherited"><td><img src="../icons/pubproperty.gif" /></td><td><a href="85ea8f89-ce59-c945-8611-3fca1a46c2bd.htm">SubType</a></td><td> (Inherited from <a href="c3ab1bce-63f5-b85a-a21f-c6e67df51d3a.htm">PARAM_Custom</a>.)<br /></td></tr><tr data="field; public; instance; declared"><td><img src="../icons/pubfield.gif" /></td><td><a href="f34a2bdc-bad1-8f91-7a6a-6167da138dad.htm">ThingMagicIDSSL900ACommandRequest</a></td><td><br /></td></tr><tr data="field; public; instance; declared"><td><img src="../icons/pubfield.gif" /></td><td><a href="5474dab8-1172-9c21-ebcc-c28140e0a8c9.htm">ThingMagicIDSSLBlock0</a></td><td><br /></td></tr><tr data="field; public; instance; declared"><td><img src="../icons/pubfield.gif" /></td><td><a href="2e1e76d6-0f86-79e1-f1db-ece0abdeef95.htm">ThingMagicIDSSLBlock1</a></td><td><br /></td></tr><tr data="method; public; instance; declared"><td><img src="../icons/pubmethod.gif" /></td><td><a href="daef1606-3de4-3ea1-72b0-c0dbc8b89e86.htm">ToBitArray(<span class="languageSpecificText"><span class="cpp">array&lt;</span></span>Boolean<span class="languageSpecificText"><span class="cpp">&gt;</span><span class="cs">[]</span><span class="vb">()</span><span class="nu">[]</span></span><span class="languageSpecificText"><span class="cpp">%</span></span>, Int32<span class="languageSpecificText"><span class="cpp">%</span></span>)</a></td><td> (Overrides <a href="c3ab1bce-63f5-b85a-a21f-c6e67df51d3a.htm">PARAM_Custom</a>.<a href="05cb1b78-9a11-80a4-d21b-baa1587089e6.htm">ToBitArray(<span class="languageSpecificText"><span class="cpp">array&lt;</span></span>Boolean<span class="languageSpecificText"><span class="cpp">&gt;</span><span class="cs">[]</span><span class="vb">()</span><span class="nu">[]</span></span><span class="languageSpecificText"><span class="cpp">%</span></span>, Int32<span class="languageSpecificText"><span class="cpp">%</span></span>)</a>.)<br /></td></tr><tr data="method; public; instance; declared"><td><img src="../icons/pubmethod.gif" /></td><td><a href="ef8c6ddb-5de4-ed15-f8ce-687fe25b69bc.htm">ToString<span class="languageSpecificText"><span class="cs">()</span><span class="cpp">()</span><span class="nu">()</span></span></a></td><td> (Overrides <a href="c3ab1bce-63f5-b85a-a21f-c6e67df51d3a.htm">PARAM_Custom</a>.<a href="dc8932ee-d87f-c6f6-fb35-c58dc73ef3a9.htm">ToString<span class="languageSpecificText"><span class="cs">()</span><span class="cpp">()</span><span class="nu">()</span></span></a>.)<br /></td></tr><tr data="field; protected; instance; inherited"><td><img src="../icons/protfield.gif" /></td><td><a href="ff7e655a-5bc3-b0d8-25a1-cc7273eaa960.htm">tvCoding</a></td><td> (Inherited from <a href="d7c4efee-cdc5-8530-b097-d1dfcd416833.htm">Parameter</a>.)<br /></td></tr><tr data="field; protected; instance; inherited"><td><img src="../icons/protfield.gif" /></td><td><a href="b6bffd2a-40fc-4a97-a8b9-893a45092631.htm">typeID</a></td><td> (Inherited from <a href="d7c4efee-cdc5-8530-b097-d1dfcd416833.htm">Parameter</a>.)<br /></td></tr><tr data="property; public; instance; inherited"><td><img src="../icons/pubproperty.gif" /></td><td><a href="e078bf3d-e640-d176-1782-da8a3148163d.htm">TypeID</a></td><td> (Inherited from <a href="d7c4efee-cdc5-8530-b097-d1dfcd416833.htm">Parameter</a>.)<br /></td></tr><tr data="property; public; instance; declared"><td><img src="../icons/pubproperty.gif" /></td><td><a href="51d0deb0-d768-a2ce-ca09-094641e0978b.htm">VENDOR_ID</a></td><td><br /></td></tr><tr data="property; public; instance; inherited"><td><img src="../icons/pubproperty.gif" /></td><td><a href="2dc8e059-3338-8c13-0764-e928b04b2446.htm">VendorID</a></td><td> (Inherited from <a href="c3ab1bce-63f5-b85a-a21f-c6e67df51d3a.htm">PARAM_Custom</a>.)<br /></td></tr><tr data="field; protected; instance; inherited"><td><img src="../icons/protfield.gif" /></td><td><a href="00a852eb-3f6d-6e2a-cbfa-15108ac4bf25.htm">VendorIdentifier</a></td><td> (Inherited from <a href="c3ab1bce-63f5-b85a-a21f-c6e67df51d3a.htm">PARAM_Custom</a>.)<br /></td></tr></table></div></div></div><div class="section"><div class="sectionTitle" onclick="toggleSection(this.parentNode)"><img src="../icons/collapse_all.gif" /> Inheritance Hierarchy</div><div class="sectionContent"><table cellspacing="0" cellpadding="0"><tr><td colspan="4"><a href="http://msdn2.microsoft.com/en-us/library/e5kfa45b" target="_blank">Object</a></td></tr><tr><td><img src="../icons/LastChild.gif" /></td><td colspan="3"><a href="d7c4efee-cdc5-8530-b097-d1dfcd416833.htm">Parameter</a></td></tr><tr><td> </td><td><img src="../icons/LastChild.gif" /></td><td colspan="2"><a href="c3ab1bce-63f5-b85a-a21f-c6e67df51d3a.htm">PARAM_Custom</a></td></tr><tr><td> </td><td> </td><td><img src="../icons/LastChild.gif" /></td><td><span class="selflink">PARAM_ThingMagicIDSSetShelfLife</span></td></tr></table></div></div><p><div id="footer"><p />Send comments on this topic to
        <a id="HT_MailLink" href="mailto:support%40thingmagic.com?Subject=Mercury API">support@thingmagic.com</a>
        <script type="text/javascript">
        var HT_mailLink = document.getElementById("HT_MailLink");
        var HT_mailLinkText = HT_mailLink.innerHTML;
        HT_mailLink.href += ": " + document.title;
        HT_mailLink.innerHTML = HT_mailLinkText;
        </script> </div>Assembly: <span sdata="assembly">LLRP</span> (Module: LLRP) Version: 1.0.0.6 (1.0.0.6)</p></div></body></html>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  ﻿<html xmlns:MSHelp="http://msdn.microsoft.com/mshelp"><head><META HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=UTF-8" /><title>MSG_DISABLE_ACCESSSPEC_RESPONSE Class</title><link rel="stylesheet" type="text/css" href="../styles/presentation.css" /><link rel="stylesheet" type="text/css" href="ms-help://Hx/HxRuntime/HxLink.css" /><script type="text/javascript" src="../scripts/script_prototype.js"> </script><script type="text/javascript" src="../scripts/EventUtilities.js"> </script><script type="text/javascript" src="../scripts/StyleUtilities.js"> </script><script type="text/javascript" src="../scripts/SplitScreen.js"> </script><script type="text/javascript" src="../scripts/ElementCollection.js"> </script><script type="text/javascript" src="../scripts/MemberFilter.js"> </script><script type="text/javascript" src="../scripts/CollapsibleSection.js"> </script><script type="text/javascript" src="../scripts/LanguageFilter.js"> </script><script type="text/javascript" src="../scripts/CookieDataStore.js"> </script><meta name="file" content="263ab889-2279-7ddd-0e15-2f6704668456" /><xml xmlns:msxsl="urn:schemas-microsoft-com:xslt"><MSHelp:Attr Name="AssetID" Value="T:Org.LLRP.LTK.LLRPV1.MSG_DISABLE_ACCESSSPEC_RESPONSE" /><MSHelp:Keyword Index="A" Term="T:Org.LLRP.LTK.LLRPV1.MSG_DISABLE_ACCESSSPEC_RESPONSE" /><MSHelp:Keyword Index="A" Term="frlrfOrgLLRPLTKLLRPV1MSG_DISABLE_ACCESSSPEC_RESPONSEClassTopic" /><MSHelp:Keyword Index="A" Term="frlrfOrgLLRPLTKLLRPV1MSG_DISABLE_ACCESSSPEC_RESPONSEMembersTopic" /><MSHelp:Keyword Index="K" Term="MSG_DISABLE_ACCESSSPEC_RESPONSE class" /><MSHelp:Keyword Index="K" Term="Org.LLRP.LTK.LLRPV1.MSG_DISABLE_ACCESSSPEC_RESPONSE class" /><MSHelp:Keyword Index="F" Term="MSG_DISABLE_ACCESSSPEC_RESPONSE" /><MSHelp:Keyword Index="F" Term="Org.LLRP.LTK.LLRPV1.MSG_DISABLE_ACCESSSPEC_RESPONSE" /><MSHelp:Attr Name="TopicType" Value="apiref" /><MSHelp:Attr Name="TopicType" Value="kbSyntax" /><MSHelp:Attr Name="APIType" Value="Managed" /><MSHelp:Attr Name="APILocation" Value="LLRP.dll" /><MSHelp:Attr Name="APIName" Value="Org.LLRP.LTK.LLRPV1.MSG_DISABLE_ACCESSSPEC_RESPONSE" /><MSHelp:Attr Name="Locale" Value="en-us" /><MSHelp:Attr Name="Abstract" Value="[Missing &lt;summary&gt; documentation for T:Org.LLRP.LTK.LLRPV1.MSG_DISABLE_ACCESSSPEC_RESPONSE]" /></xml></head><body><div id="control"><span class="productTitle">Mercury API</span><br /><span class="topicTitle">MSG_DISABLE_ACCESSSPEC_RESPONSE Class</span><br /><div id="toolbar"><span id="chickenFeet"><a href="d4648875-d41a-783b-d5f4-638df39ee413.htm">Namespaces</a> ► <a href="d23cd0df-7044-bf8b-2790-d9664b592b4a.htm">Org.LLRP.LTK.LLRPV1</a> ► <span class="selflink">MSG_DISABLE_ACCESSSPEC_RESPONSE</span></span><span id="languageFilter"><select id="languageSelector" onchange="var names = this.value.split(' '); toggleVisibleLanguage(names[1]); lfc.switchLanguage(names[0]); store.set('lang',this.value); store.save();"><option value="CSharp cs">C#</option><option value="VisualBasic vb">Visual Basic</option><option value="ManagedCPlusPlus cpp">Visual C++</option></select></span></div></div><div id="main"><span style="color: DarkGray"> </span><div class="summary"><p style="color: #dc143c; font-size: 8.5pt; font-weight: bold;">[Missing &lt;summary&gt; documentation for T:Org.LLRP.LTK.LLRPV1.MSG_DISABLE_ACCESSSPEC_RESPONSE]</p></div><div class="section"><div class="sectionTitle" onclick="toggleSection(this.parentNode)"><img src="../icons/collapse_all.gif" /> Declaration Syntax</div><div class="sectionContent"><div id="syntaxSection"><table class="filter"><tr class="tabs" id="syntaxTabs"><td class="tab" x-lang="CSharp" onclick="toggleClass('syntaxTabs','x-lang','CSharp','activeTab','tab'); toggleStyle('syntaxBlocks','x-lang','CSharp','display','block','none');">C#</td><td class="tab" x-lang="VisualBasic" onclick="toggleClass('syntaxTabs','x-lang','VisualBasic','activeTab','tab'); toggleStyle('syntaxBlocks','x-lang','VisualBasic','display','block','none');">Visual Basic</td><td class="tab" x-lang="ManagedCPlusPlus" onclick="toggleClass('syntaxTabs','x-lang','M﻿<html xmlns:MSHelp="http://msdn.microsoft.com/mshelp"><head><META HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=UTF-8" /><title>ValidateParameterKey Method (key)</title><link rel="stylesheet" type="text/css" href="../styles/presentation.css" /><link rel="stylesheet" type="text/css" href="ms-help://Hx/HxRuntime/HxLink.css" /><script type="text/javascript" src="../scripts/script_prototype.js"> </script><script type="text/javascript" src="../scripts/EventUtilities.js"> </script><script type="text/javascript" src="../scripts/StyleUtilities.js"> </script><script type="text/javascript" src="../scripts/SplitScreen.js"> </script><script type="text/javascript" src="../scripts/ElementCollection.js"> </script><script type="text/javascript" src="../scripts/MemberFilter.js"> </script><script type="text/javascript" src="../scripts/CollapsibleSection.js"> </script><script type="text/javascript" src="../scripts/LanguageFilter.js"> </script><script type="text/javascript" src="../scripts/CookieDataStore.js"> </script><meta name="file" content="c993be24-9a64-86e5-7bc2-af9967460b4c" /><xml xmlns:msxsl="urn:schemas-microsoft-com:xslt"><MSHelp:Attr Name="AssetID" Value="M:ThingMagic.Reader.ValidateParameterKey(System.String)" /><MSHelp:Keyword Index="A" Term="M:ThingMagic.Reader.ValidateParameterKey(System.String)" /><MSHelp:Keyword Index="A" Term="frlrfThingMagicReaderClassValidateParameterKeyTopic" /><MSHelp:Keyword Index="K" Term="ValidateParameterKey method" /><MSHelp:Keyword Index="K" Term="Reader.ValidateParameterKey method" /><MSHelp:Keyword Index="F" Term="ValidateParameterKey" /><MSHelp:Keyword Index="F" Term="Reader.ValidateParameterKey" /><MSHelp:Keyword Index="F" Term="ThingMagic.Reader.ValidateParameterKey" /><MSHelp:Attr Name="TopicType" Value="apiref" /><MSHelp:Attr Name="TopicType" Value="kbSyntax" /><MSHelp:Attr Name="APIType" Value="Managed" /><MSHelp:Attr Name="APILocation" Value="MercuryAPI.dll" /><MSHelp:Attr Name="APIName" Value="ThingMagic.Reader.ValidateParameterKey" /><MSHelp:Attr Name="Locale" Value="en-us" /><MSHelp:Attr Name="Abstract" Value="Check for existence of parameter. Throw exception if parameter does not exist." /></xml></head><body><div id="control"><span class="productTitle">Mercury API</span><br /><span class="topicTitle">ValidateParameterKey Method (key)</span><br /><div id="toolbar"><span id="chickenFeet"><a href="d4648875-d41a-783b-d5f4-638df39ee413.htm">Namespaces</a> ► <a href="3af3f7df-e311-4e3f-9388-449f848a997b.htm">ThingMagic</a> ► <a href="9a8bf2e6-b158-4467-a1db-040f0990f32d.htm">Reader</a> ► <span class="selflink">ValidateParameterKey(String)</span></span><span id="languageFilter"><select id="languageSelector" onchange="var names = this.value.split(' '); toggleVisibleLanguage(names[1]); lfc.switchLanguage(names[0]); store.set('lang',this.value); store.save();"><option value="CSharp cs">C#</option><option value="VisualBasic vb">Visual Basic</option><option value="ManagedCPlusPlus cpp">Visual C++</option></select></span></div></div><div id="main"><span style="color: DarkGray"> </span><div class="summary">
            Check for existence of parameter.  Throw exception if parameter does not exist.
            </div><div class="section"><div class="sectionTitle" onclick="toggleSection(this.parentNode)"><img src="../icons/collapse_all.gif" /> Declaration Syntax</div><div class="sectionContent"><div id="syntaxSection"><table class="filter"><tr class="tabs" id="syntaxTabs"><td class="tab" x-lang="CSharp" onclick="toggleClass('syntaxTabs','x-lang','CSharp','activeTab','tab'); toggleStyle('syntaxBlocks','x-lang','CSharp','display','block','none');">C#</td><td class="tab" x-lang="VisualBasic" onclick="toggleClass('syntaxTabs','x-lang','VisualBasic','activeTab','tab'); toggleStyle('syntaxBlocks','x-lang','VisualBasic','display','block','none');">Visual Basic</td><td class="tab" x-lang="ManagedCPlusPlus" onclick="toggleClass('syntaxTabs','x-lang','ManagedCPlusPlus','activeTab','tab'); toggleStyle('syntaxBlocks','x-lang','ManagedCPlusPlus','display','block','none');">Visual C++</td></tr></table><div id="syntaxBlocks"><div class="code" x-lang="CSharp"><pre>
<span class="keyword">protected</span> <a href="d1c1bc66-2df8-bc59-71d4-b27b42bd0291.htm">Reader<span class="languageSpecificText"><span class="cs">.</span><span class="vb">.</span><span class="cpp">::</span><span class="nu">.</span></span>Setting</a> <span class="identifier">ValidateParameterKey</span>(
	<a href="http://msdn2.microsoft.com/en-us/library/s1wwdcbf" target="_blank">string</a> <span class="parameter">key</span>
)</pre></div><div class="code" x-lang="VisualBasic"><pre>
<span class="keyword">Protected</span> <span class="keyword">Function</span> <span class="identifier">ValidateParameterKey</span> ( _
	<span class="parameter">key</span> <span class="keyword">As</span> <a href="http://msdn2.microsoft.com/en-us/library/s1wwdcbf" target="_blank">String</a> _
) <span class="keyword">As</span> <a href="d1c1bc66-2df8-bc59-71d4-b27b42bd0291.htm">Reader<span class="languageSpecificText"><span class="cs">.</span><span class="vb">.</span><span class="cpp">::</span><span class="nu">.</span></span>Setting</a></pre></div><div class="code" x-lang="ManagedCPlusPlus"><pre>
<span class="keyword">protected</span>:
<a href="d1c1bc66-2df8-bc59-71d4-b27b42bd0291.htm">Reader<span class="languageSpecificText"><span class="cs">.</span><span class="vb">.</span><span class="cpp">::</span><span class="nu">.</span></span>Setting</a>^ <span class="identifier">ValidateParameterKey</span>(
	<a href="http://msdn2.microsoft.com/en-us/library/s1wwdcbf" target="_blank">String</a>^ <span class="parameter">key</span>
)</pre></div></div></div></div></div><div id="parameters"><div class="section"><div class="sectionTitle" onclick="toggleSection(this.parentNode)"><img src="../icons/collapse_all.gif" /> Parameters</div><div class="sectionContent"><dl paramName="key"><dt><span class="parameter">key</span> (<a href="http://msdn2.microsoft.com/en-us/library/s1wwdcbf" target="_blank">String</a>)</dt><dd>Parameter name</dd></dl></div></div></div><div class="section"><div class="sectionTitle" onclick="toggleSection(this.parentNode)"><img src="../icons/collapse_all.gif" /> Return Value</div><div class="sectionContent">Setting if key is valid.  Otherwise, throws ArgumentException.</div></div><p><div id="footer"><p />Send comments on this topic to
        <a id="HT_MailLink" href="mailto:support%40thingmagic.com?Subject=Mercury API">support@thingmagic.com</a>
        <script type="text/javascript">
        var HT_mailLink = document.getElementById("HT_MailLink");
        var HT_mailLinkText = HT_mailLink.innerHTML;
        HT_mailLink.href += ": " + document.title;
        HT_mailLink.innerHTML = HT_mailLinkText;
        </script> </div>Assembly: <span sdata="assembly">MercuryAPI</span> (Module: MercuryAPI) Version: 1.21.4.61 (1.21.4.61)</p></div></body></html>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 ﻿<html xmlns:MSHelp="http://msdn.microsoft.com/mshelp"><head><META HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=UTF-8" /><title>OpSpecID Field</title><link rel="stylesheet" type="text/css" href="../styles/presentation.css" /><link rel="stylesheet" type="text/css" href="ms-help://Hx/HxRuntime/HxLink.css" /><script type="text/javascript" src="../scripts/script_prototype.js"> </script><script type="text/javascript" src="../scripts/EventUtilities.js"> </script><script type="text/javascript" src="../scripts/StyleUtilities.js"> </script><script type="text/javascript" src="../scripts/SplitScreen.js"> </script><script type="text/javascript" src="../scripts/ElementCollection.js"> </script><script type="text/javascript" src="../scripts/MemberFilter.js"> </script><script type="text/javascript" src="../scripts/CollapsibleSection.js"> </script><script type="text/javascript" src="../scripts/LanguageFilter.js"> </script><script type="text/javascript" src="../scripts/CookieDataStore.js"> </script><meta name="file" content="774f1b5f-7fb6-88d3-4df8-4d00d1a8fd27" /><xml xmlns:msxsl="urn:schemas-microsoft-com:xslt"><MSHelp:Attr Name="AssetID" Value="F:Org.LLRP.LTK.LLRPV1.thingmagic.PARAM_ThingMagicHiggs3FastLoadImageOpSpecResult.OpSpecID" /><MSHelp:Keyword Index="A" Term="F:Org.LLRP.LTK.LLRPV1.thingmagic.PARAM_ThingMagicHiggs3FastLoadImageOpSpecResult.OpSpecID" /><MSHelp:Keyword Index="A" Term="frlrfOrgLLRPLTKLLRPV1thingmagicPARAM_ThingMagicHiggs3FastLoadImageOpSpecResultClassOpSpecIDTopic" /><MSHelp:Keyword Index="K" Term="OpSpecID field" /><MSHelp:Keyword Index="K" Term="PARAM_ThingMagicHiggs3FastLoadImageOpSpecResult.OpSpecID field" /><MSHelp:Keyword Index="F" Term="OpSpecID" /><MSHelp:Keyword Index="F" Term="PARAM_ThingMagicHiggs3FastLoadImageOpSpecResult.OpSpecID" /><MSHelp:Keyword Index="F" Term="Org.LLRP.LTK.LLRPV1.thingmagic.PARAM_ThingMagicHiggs3FastLoadImageOpSpecResult.OpSpecID" /><MSHelp:Attr Name="TopicType" Value="apiref" /><MSHelp:Attr Name="TopicType" Value="kbSyntax" /><MSHelp:Attr Name="APIType" Value="Managed" /><MSHelp:Attr Name="APILocation" Value="LLRP.dll" /><MSHelp:Attr Name="APIName" Value="Org.LLRP.LTK.LLRPV1.thingmagic.PARAM_ThingMagicHiggs3FastLoadImageOpSpecResult.OpSpecID" /><MSHelp:Attr Name="Locale" Value="en-us" /><MSHelp:Attr Name="Abstract" Value="[Missing &lt;summary&gt; documentation for F:Org.LLRP.LTK.LLRPV1.thingmagic.PARAM_ThingMagicHiggs3FastLoadImageOpSpecResult.OpSpecID]" /></xml></head><body><div id="control"><span class="productTitle">Mercury API</span><br /><span class="topicTitle">OpSpecID Field</span><br /><div id="toolbar"><span id="chickenFeet"><a href="d4648875-d41a-783b-d5f4-638df39ee413.htm">Namespaces</a> ► <a href="8ff80a0c-797f-94c7-03ae-23332b0ef831.htm">Org.LLRP.LTK.LLRPV1.thingmagic</a> ► <a href="7e9badf0-2f8e-cabc-1494-7c951ac844f9.htm">PARAM_ThingMagicHiggs3FastLoadImageOpSpecResult</a> ► <span class="selflink">OpSpecID</span></span><span id="languageFilter"><select id="languageSelector" onchange="var names = this.value.split(' '); toggleVisibleLanguage(names[1]); lfc.switchLanguage(names[0]); store.set('lang',this.value); store.save();"><option value="CSharp cs">C#</option><option value="VisualBasic vb">Visual Basic</option><option value="ManagedCPlusPlus cpp">Visual C++</option></select></span></div></div><div id="main"><span style="color: DarkGray"> </span><div class="summary"><p style="color: #dc143c; font-size: 8.5pt; font-weight: bold;">[Missing &lt;summary&gt; documentation for F:Org.LLRP.LTK.LLRPV1.thingmagic.PARAM_ThingMagicHiggs3FastLoadImageOpSpecResult.OpSpecID]</p></div><div class="section"><div class="sectionTitle" onclick="toggleSection(this.parentNode)"><img src="../icons/collapse_all.gif" /> Declaration Syntax</div><div class="sectionContent"><div id="syntaxSection"><table class="filter"><tr class="tabs" id="syntaxTabs"><td class="tab" x-lang="CSharp" onclick="toggleClass('syntaxTabs','x-lang','CSharp','activeTab','tab'); toggleStyle('syntaxBlocks','x-lang','CSharp','display','block','none');">C#</td><td class="tab" x-lang="VisualBasic" onclick="toggleClass('syntaxTabs','x-lang','VisualBasic','activeTab','tab'); toggleStyle('syntaxBlocks','x-lang','VisualBasic','display','block','none');">Visual Basic</td><td class="tab" x-lang="ManagedCPlusPlus" onclick="toggleClass('syntaxTabs','x-lang','ManagedCPlusPlus','activeTab','tab'); toggleStyle('syntaxBlocks','x-lang','ManagedCPlusPlus','display','block','none');">Visual C++</td></tr></table><div id="syntaxBlocks"><div class="code" x-lang="CSharp"><pre>
<span class="keyword">public</span> <a href="http://msdn2.microsoft.com/en-us/library/s6eyk10z" target="_blank">ushort</a> <span class="identifier">OpSpecID</span></pre></div><div class="code" x-lang="VisualBasic"><pre>
<span class="keyword">Public</span> <span class="identifier">OpSpecID</span> <span class="keyword">As</span> <a href="http://msdn2.microsoft.com/en-us/library/s6eyk10z" target="_blank">UShort</a></pre></div><div class="code" x-lang="ManagedCPlusPlus"><pre>
<span class="keyword">public</span>:
<a href="http://msdn2.microsoft.com/en-us/library/s6eyk10z" target="_blank">unsigned short</a> <span class="identifier">OpSpecID</span></pre></div></div></div></div></div><p><div id="footer"><p />Send comments on this topic to
        <a id="HT_MailLink" href="mailto:support%40thingmagic.com?Subject=Mercury API">support@thingmagic.com</a>
        <script type="text/javascript">
        var HT_mailLink = document.getElementById("HT_MailLink");
        var HT_mailLinkText = HT_mailLink.innerHTML;
        HT_mailLink.href += ": " + document.title;
        HT_mailLink.innerHTML = HT_mailLinkText;
        </script> </div>Assembly: <span sdata="assembly">LLRP</span> (Module: LLRP) Version: 1.0.0.6 (1.0.0.6)</p></div></body></html>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            ����          �System.Collections.Generic.Dictionary`2[[System.String, mscorlib, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089],[System.Collections.Generic.List`1[[System.Int64, mscorlib, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]], mscorlib, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]]   VersionComparerHashSizeKeyValuePairs  �System.Collections.Generic.GenericEqualityComparer`1[[System.String, mscorlib, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]]�System.Collections.Generic.KeyValuePair`2[[System.String, mscorlib, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089],[System.Collections.Generic.List`1[[System.Int64, mscorlib, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]], mscorlib, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]][]d   	   �   	      �System.Collections.Generic.GenericEqualityComparer`1[[System.String, mscorlib, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]]           d   �System.Collections.Generic.KeyValuePair`2[[System.String, mscorlib, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089],[System.Collections.Generic.List`1[[System.Int64, mscorlib, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]], mscorlib, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]]�����System.Collections.Generic.KeyValuePair`2[[System.String, mscorlib, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089],[System.Collections.Generic.List`1[[System.Int64, mscorlib, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]], mscorlib, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]]   keyvalue~System.Collections.Generic.List`1[[System.Int64, mscorlib, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]]   length	   ��������   llrp		   ��������   ltk	   ��������   llrpv1	   ��������   level	   ��������   literal	   ��������   link	   ��������   list	   ��������   load	   ��������    listener	!   ��������#   
llrpstatus	$   ��������&   limit	'   ��������)   location	*   ��������,   logical	-   ��������/   
llrpclient	0   ��������2   logging	3   ��������5   log	6   ��������8   llrpendpoint	9   ��������;   long	<   ��������>   loggingform	?   ��������A   llrpbitarray	B   ��������D   	loglimits	E   ��������G   limits	H   ��������J   logmodedata	K   ��������M   loglimit	N   ��������P   limitcounter	Q   ��������S   
lockaction	T   ��������V   llrpnetworkexception	W   ��������Y   locktag	Z   ��������\   lock	]   ��������_   locked	`   ��������b   locking	c   ��������e   lsb	f   ��������h   
llrpreader	i   ��������k   
lowbattery	l   ��������n   low	o   ��������q   lv3	r   ��������t   linear	u   ��������w   llrpconstants	x   ��������z   	loadimage	{   ��������}   
licensekey	~   ���������   life	�   ~��������   lower	�   {��������   lbt	�   x��������   llrpfirmwareloadoptions	�   u��������   llrpextensionconstants	�   r��������   loads	�   o��������   license	�   l��������   levels	�   i��������   loss	�   f��������   logstatebytestream	�   c��������   local	�   `��������   linkfrequency	�   ]��������   lockactions	�   Z��������   llrpvendorconstants	�   W��������   loadvendorextensionassembly	�   T��������   len	�   Q��������   llrpmessagetypepair	�   N��������   
loghandler	�   K��������   llrp_reader_name	�   H��������   lockoperations	�   E��������   llrpxmlparser	�   B��������   like	�   ?��������   	listeners	�   <��������   logstate	�   9��������   layer	�   6��������   lockbits	�   3��������   loginterval	�   0��������   longer	�   -��������   logic	�   *��������   lastseentimestampuptime	�   '��������   lastseentimestamputc	�   $��������   
link250khz	�   !��������   
link320khz	�   ��������   
link640khz	�   ��������   lockfailures	�   ��������   	locations	�   ��������   
lowerlimit	�   ��������   limited	�   ��������   llrpbinarydecoder	�   ��������   llrp_envelope	�   	��������   loader	�   ��������   logger	�   ��������   llrpconfigurationstatevalue	�    �������  language	  ��������  llrpcapabilities	  ��������  listen	  ��������
  
link160khz	  ��������  	link40khz	  ��������  
limitcount	  ��������  
lbtenabled	  ��������  limitscrossing	  ��������  lcontrolword	  ��������  llrp_capabilities	  ��������  llrp_air_protocol_capabilities	   ��������"  lkoption	#  ��������%  lessthan	&  ��������(  level2	)  ��������+  large_tag_population_support	,  ��������.  large	/     ~System.Collections.Generic.List`1[[System.Int64, mscorlib, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]]   _items_size_version  		0  �  �  	      	1  e  e        	2  O  O        	3  O  O        	4  Q   Q         	5  G   G         	6  J   J         	7  =   =         	8        !      	9        $      	:  -   -   '      	;        *      	<        -      	=  	   	   0      	>  )   )   3      	?        6      	@  9   9   9      	A        <      	B        ?      	C        B      	D        E      	E        H      	F  	   	   K      	G        N      	H        Q      	I  	   	   T      	J  $   $   W      	K        Z      	L        ]      	M  D   D   `      	N        c      	O        f      	P        i      	Q        l      	R        o      	S        r      	T        u      	U        x      	V        {      	W  	   	   ~      	X        �      	Y        �      	Z        �      	[        �      	\        �      	]        �      	^        �      	_        �      	`        �      	a        �      	b        �      	c        �      	d        �      	e        �      	f        �      	g        �      	h        �      	i        �      	j        �      	k        �      	l        �      	m        �      	n        �      	o  	   	   �      	p  
   
   �      	q        �      	r  
   
   �      	s        �      	t        �      	u        �      	v        �      	w        �      	x        �      	y        �      	z        �      	{        �      	|        �      	}        �      	~        �      	        �      	�        �      	�        �      	�        �      	�             	�             	�             	�             	�             	�             	�             	�             	�             	�             	�              	�        #     	�        &     	�        )     	�        ,     	�        /     	�        0     	                    %      *      +      1      7      <      M      N      V      y      }      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �                &     .     1     7     >     @     I     K     R     ]     k     r     s     |     �     �     �     �     �     �     �     �     �     �                     #     )     /     3     4     5     7     F     Q     T     l     �     �     �     �     �     �     �     �     �                              "     %     3     F     G     H     \     b     d     l     n     p     }     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                               :     @     A     B     M     T     Z     [     _     b     c     d     f     i     k     o     q     t     v     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                              !     (     *     -     /     0     1     E     R          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                   %     )     +     7     9     D     F     H     N     W     b     c     g     m     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                              #     *     -     0     7     ?     A     N     b     k     p     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                         %     (     +     0     3     7     9     =     ?     F     L     M     R     S     T     `     t     x     z     {     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     	     		     	     	     )	     0	     6	     K	     T	     W	     m	     o	     w	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     
     
     
     
     
     +
     -
     .
     /
     @
     b
     m
     n
     z
     ~
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
                    #     :     >     ?     O     Q     s     u     |     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                    ,     -     @     C     N     Q     U     \     h     j     z     ~     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                    4     7     8     @     M     P     Q     S     ]     g     r     t     {     |     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �          )     8     P     R     W     n     o     q     s     t     �     �     �     �     �     �     �     �     �     �     �                                             #     *     /     6     9     ;     G     Y     b     f     j     p     q     s     w     x     ~     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                              "     G     N     U     [     _     d     e     h     o     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                    (     :     >     O     Y     b     f     q     s     w     y          �     �     �     �     �     �     �     �     �     �     �     �     �     �     (     7     8     9     ;     =     >     Z     \     ^     a     b     e     i     l     m     w     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                         0     8     =     D     L     P     b     s     z     }     ~     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                         /     7     <     B     R     V     Y     Z     d     h     {     �     �     �     �     �     �     �     �     �                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    1     	                                     	             	      
                                                                                     !      #      $      %      &      '      *      +      ,      -      /      0     	 2      3      4      6      7      9      :      ;      <      =      >      A      B      C      D      E      F      H      I      J      K      L      M      N      O      Q      R      S      V      W      Y      Z      [      ]      ^      _      b      d      f      g      h     	 i      j      l      p      r      s      t     	 u      x      y      {      |      }      ~            �      �      �      �      �     	 �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �     	 �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �     	 �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �                                          	     
                                                                                               !     "     %     &     '     (     *     .     /     0     1     2     3     6     7     9     :     <     =     >     @     A     B     C     D     E     H     I     K     L    	 M     N     O     Q     R     S     T     X     Y    	 Z     [     \     ]     _     `     a     b     c     e     f     g     h     k     l     m     n     o     q     r     s     u    	 v     x     |    	 }     ~     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �                         	                                                                       !     #     %     '     (     )     +     -     .     /     0     1     2     3     4     5     6     7     8     ;     <     =     >     ?     A     B     D     E     F     G     J     K     L     M     Q     S     T     U     V     W     Y     [     \     ^     _    	 `     c     d     e     f     g     h     i     j     l    	 n     o     p     q     r     s     t     u     v     w     y     z     {     }     ~          �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                   	     
                                                                                           !     "     #     $     %     &     (     )     +    	 ,     -     .     /     1     2     3     5     6     8     :     ;     <     =    	 >    	 ?     @     B     C     E     F     G     H     J    	 K     M     N     O    	 Q    	 S     U     V     W     X    	 Y    	 Z     [     \     ]     ^     _     `     a     b     c     d     e     h     i     j     l     m     n     o     p     q     t     x     y     z     {     |     }     ~     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                         	                                                 	                           !     #     $     %     &    	 '    	 (     )     +     .     0     1     2     3     4     5     6     7     8     9     :     <     =     >     ?     @     A     B     C     D     F     G     K     L     M    	 N     O     Q     S     T     U     V     W     X     Y     Z     [     \     ]     ^     _     b     c     d     e     f     i     j     k     l     n     o     p     q     t     u     v     w     x     y     z     {     }     ~          �     �     �     �     �     �     �     �    	 �    	 �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �                              	 
         	                                                                           	       !     "     #     &     (     *     +    	 ,     -     /     0     2     3     4     5     6     7     9     ;     <     =     >     ?     @     D     E     F     G     H     I     K    	 L     M     N     O     P     Q     R     S     V     W     X    	 [     \     ]     ^     _     `     c     d    	 f     j     k     m     n     o    	 s     t     u     v     x     y     z     {    	 |     }     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                              	     
                                                                                                     !     "     #     %     &     '     )     +     ,     .     0     1     2     3     4     9     :     ;     <     =     >     ?     @     A     B     C     D     E     H     I     J     L     M     N     O     P     Q     R     S     U     V     W     X     Y     Z     [    	 \     ]     ^     _     `     a     b     c     d    	 e     g     j     l     m     o     q    	 r     t     u     v     w     z     |     }    	 ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �    	 �     �    	 �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �    	                    	           	     
                                                                                           !     #     $     &     (     +     ,     -     .     0     1     2     3     4     5     7     9     :     <     >     ?     @     A     B     C     D     E     F     I     J     K     L     M     N     O     Q     R     S     T     U    	 V    	 W     X     Y     [     ]     _     `     a     b     c    	 d     e     f    	 g     h     j     k     m     o     p     r    	 t     u     v    	 y     {     |     }          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �                                    	                                                                                                "     %     '     (     *     +     ,     .     0    	 2     3     4     5     6     7     8     9     =     >     ?     @     A     B     C     D     E     F     G     I     J     L     M     N     O     P     R     S     T     V     W     X     Y     Z     [     \     ]     ^     _     `     a     c     d     f     g     h     i     j     l     n     o     p     q     t     u     v     x     z     {     |     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �      	    	 	     	     	     	     	     	     	     	     		     
	     	     	     	     	     	     	     	     	     	     	     	    	 	     	      	     !	     $	     %	     '	     )	     +	     -	     .	     0	     2	     4	     5	     6	     7	     9	     :	     ;	     =	     @	     B	     C	     E	     F	     G	     J	     K	     L	     M	     N	    	 O	     P	     Q	    	 S	     T	     W	     [	     \	    	 ]	     ^	    	 _	     `	     a	     c	     e	     f	     g	     h	     k	     l	     m	     o	     p	     r	     s	     t	     w	     y	     {	     |	     }	     ~	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	    	 �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	    	 �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	    	 �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     
     
     
     
     
     
     
    	 	
     

     
     
     
     
     
     
     
    	 
     
     
     
     !
     #
     %
     &
     '
     )
     *
     +
     -
     .
     /
     0
     1
     2
     4
     6
     8
     9
     :
     ;
     <
     =
     ?
     @
     A
     B
     C
     E
     F
     G
     H
     I
    	 J
     K
     L
     M
     O
     P
     Q
     R
     S
     T
     U
     V
     W
     X
     Y
     Z
     [
     \
     ]
     ^
     _
     `
     b
     c
     d
    	 e
     f
     g
     h
     i
    	 j
     k
     l
     m
     n
     o
     p
     s
     t
     u
     x
     z
     {
     |
     }
     ~
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
    	 �
     �
     �
     �
    	 �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
    	 �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
    	 �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
                          
                                                                          	           !     "     #     $     %     '     (     )     *     +     ,    	 -     .     /     0     3     7     8     9     :     <     =     >     ?     @     E     H     J     K     L     M    	 N     O     Q     R     T     U     X     Z     ]     _     `     c     e     g     h     i     k     m     n     o     r     s     t     u     v     w     y     z    	 {     }     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �    	 �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �    	 �     �    	 �     �     �     �     �                               	     
         	                                             	                     !     "     #     $     %     &     '     (     )     *     ,     -     /     0     1     3     4     5     8     9     :     =     >     ?     @     B     C     D     E     F     G     H     J     K     L     M     N     O     P     Q     R     U     W     X     Z     \    	 ^     _     `     a     b     c     e     h     i     j     l     m     o     p     q     r     s     t     u     w     x     z     {     |     }     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                         
                                                                                                    	 "    	 #     $     &     '     (     -     .     /     0     2     4     5     6     7     8     9     :     ;     <     =     @     A     B     C     D     E     F     G     H     I     K     L     M     N     O     P     Q     S     T     U     V     W     X     Y     Z     [     \     ]     ^     _     `     a     b     d     f     g     h     i     j     k     l     m     n     o     p     q     r     s     t     u     v     x     y     z     {     |     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �                              	         	                                                                                            "     #     $     '     )     +     ,    	 -     .     /     0     1     2     3     4     5     6     7     8     9     :     ;     >     ?     B     C     D     E     G     H     I    	 K     L     M     N     O     P     Q     R     S     T     U     W    	 Y     ]     ^     _     `     a     b     d     e     f     h     i     k     n     o     p     q     s     t     v     w     {     |    	 ~          �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �          	               	                          	     
    	                         	                                                                        !     "     #     $     &     (     )     *     +     ,     -     .     /     0     1    	 2     3     4     5     6     8     9     :     ;     <     ?     @    	 A     C     D     E     G     H     I    	 J    	 K     L     M     N     O     P     R     S    	 U     V     W     X     Y     Z     [     ]    	 ^     _     `     a     b     e     f     g     i     j     k     l     m     o     p     q     r     s     v     w     x     y     z     {     |     }     ~     �     �     �     �     �     �    	 �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �    	 �     �    	 �     �     �     �     �     �     �     �     �     �     �     �    	 �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                              	 
                                                                                                     !     "     %     &     '     )     +     ,     -     .     /     1     2     3     5     7     8     9     <    	 =     >     ?     @     A     B     C     D     E     F     G     H     I     K     L     M     N     P     Q     R     S     T     U     V     W     Y     Z     [     ]     ^     _     b     c     d     e     f     h     i     k     m     n     o     q     s     t     u     v     w     y     z     {     ~          �    	 �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	                                                                                                  $    	 %    	 &     (     )     +     ,    	 -     .     0     1     2    	 3     5     6     8     9     :     ;     <     =     >     @     A     D     G     H     K     M     N     O     P     Q     R    	 S     U     V     W     X     Y     Z     _     b     c     d     e     f     g     h     i     l     m     n     o     p     q    	 r     s     u     v     w     x     y     z     |     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                          	     
                                                 	                    	                           !     #    	 $    	 %     &     '     (     *     +    	 ,     .     /     0     1     2     4     5     6     7     8     9     :     ;     <     =     >     ?     @     A     B     C     D     E     F    	 G     H     I     J     K     M     N     P     Q     R     S    	 T     V     W     X     \     ^     a     b     c     e     f     g     h     i     j     k     l     m     n     q     r     t     u     v     w     x     z     {     |     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �    	 �     �     �     �    	 �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �    	 �    	 �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                    
                                                                                      "     #     $     %     &     )     +     ,     .     0     2     3     5     6     8     :     <     =     ?     @     A     B     D     F     G     H     I     L     M     O     P     R     T     U     V     X     [     ]     ^     _     `     a     b     c     d     e     f     h     i    	 l     o     p     q     r     s     u     y     z     }     ~          �     �     �     �    	 �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                         	                                                                                                !     $     %     '     +     ,     -     /    	 1     2     3     4    	 5     7     8     9     :     <     ?     @     B     C     D     G     J     K     L     M     N     P     R     S    	 T     U     W     Y     [     \     ]     ^     _     `     b     c     d     f     h     i     k     l     m     n     o     p     q     r     s     w     x     y     z     {     |     }     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �    	 �     �     �     �     �     �     �     �                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            2     	                                                  	      
                                                                                     !      #      $      %      &      '      *      +      ,      -      /      0      2      3      4      6      7      9      :      ;      <      =      >      A      B      C      D      E      F      H      I      J      K      L      M      N      O      Q      R      S      V      W      Y      Z      [      ]      ^      _      b      d      f      g      h      i      j      l      p      r      s      t      u      x      y      {      |      }      ~            �      �      �      �      �      �      �      �      �     	 �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �                                          	     
                                                                                               !     "     %     &     (     *     .     /     0     1     2     3     6     7     9     :     <     =     >     @     A     B     C     D     E     H     I     K     L     M     N     O     Q     R     S     T     X     Y     Z     [     ]     _     `     a     b     c     e     f     g     h     k     l     m     n     o     q     r     s     u     v     x     |     }     ~     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                         	                                                                       !     #     %     '     (     )     +     -     .     /     0     1     2     3     4     5     6     7     8     ;     <     =     >     ?     A     B     D     E     F     G     J     K     L     M     Q     S     T     U     V     W     Y     [     \     ^     _     `     c     d     e     f     g     h     i     j     l     n     o     p     q     r     s     t     u     v     w     y     z     {     }     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                   	     
                                                                                           "     #     $     %     &     (     )     +     ,     -     .     /     1     2     3     5     6     8     :     ;     <     =     >     ?     @     B     C     E     F     G     H     J     K     M     N     O     Q     S     U     V     W     X     Y     Z     [     \     ]     ^     _     `     a     b     c     d     e     h     i     j     l     m     n     o     p     q     t     x     y     z     {     |     }     ~     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                         	                                                                            !     #     $     %     &     '     (     )     +     .     0     1     2     3     4     5     6     7     8     9     :     <     =     >     ?     @     A     B     C     D     F     G     K     L     M     N     O     Q     S     T     U     V     W     X     Y     Z     [     \     ]     ^     _     b     c     d     e     f     i     j     k     l     n     o     p     q     t     u     v     w     x     y     z     {     }     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                               
                                                                                           !     "     #     &     (     *     +     ,     -     /     0     2     3     4     5     6     7     9     ;     <     =     >     ?     @     D     E     F     G     H     I     K     L     M     N     O     P     Q     R     S     V     W     X     [     \     ]     ^     _     `     c     d     f     j     k     m     n     o     s     t     u     v     x     y     z     {     |     }     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                              	     
                                                                                                     !     "     #     %     &     '     )     +     ,     .     0     1     2     3     4     9     :     ;     <     =     >     ?     @     A     B     C     D     E     H     I     J     L     M     N     O     P     Q     R     S     U     V     W     X     Y     Z     [     \     ]     ^     _     `     a     b     c     d     e     g     l     m     o     q     r     t     u     v     w     z     |     }     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                   	     
                                                                                           !     #     $     &     (     +     ,     -     0     1     2     3     4     5     7     9     :     <     >     ?     @     A     B     C     D     E     F     I     J     K     L     M     N     O     Q     R     S     T     U     V     W     X     Y     [     ]     _     `     a     b     c     d     e     f     g     h     j     k     m     o     p     r     t     u     v     y     {     |     }          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                    	                                                                                                "     %     '     (     *     +     ,     .     0     2     3     4     5     6     7     8     9     =     >     ?     @     A     B     C     D     E     F     G     I     J     L     M     N     O     P     R     S     T     V     W     X     Y     Z     [     \     ]     ^     _     `     a     c     d     f     g     h     i     j     l     n     o     p     q     t     u     v     x     z     {     |     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �      	     	     	     	     	     	     	     	     	     		     
	     	     	     	     	     	     	     	     	     	     	     	     	     	      	     !	     $	     %	     '	     )	     +	     -	     .	     0	     2	     4	     5	     6	     7	     9	     :	     ;	     =	     @	     B	     C	     E	     F	     G	     J	     K	     L	     M	     N	     O	     P	     Q	     S	     T	     W	     [	     \	     ]	     ^	     _	     `	     a	     c	     e	     f	     g	     h	     k	     l	     m	     o	     p	     r	     s	     t	     w	     y	     {	     |	     }	     ~	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     
     
     
     
     
     
     
     	
     

     
     
     
     
     
     
     
     
     
     
     
     !
     #
     %
     &
     '
     )
     *
     +
     -
     .
     /
     0
     1
     2
     4
     6
     8
     9
     :
     ;
     <
     =
     ?
     @
     A
     B
     C
     E
     F
     G
     H
     I
     J
     K
     L
     M
     P
     Q
     R
     S
     T
     U
     V
     W
     X
     Y
     Z
     [
     \
     ]
     ^
     _
     `
     b
     c
     d
     e
     f
     g
     h
     i
     j
     k
     l
     m
     n
     o
     p
     s
     t
     u
     x
     z
     {
     |
     }
     ~
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
                          
                                                                                     !     "     #     $     %     '     (     )     *     +     ,     -     .     /     0     3     7     8     :     <     =     >     ?     @     E     H     J     K     M     N     O     Q     R     T     U     X     Z     ]     _     `     c     e     g     h     i     k     m     n     o     r     s     t     u     v     w     y     z     {     }     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                               	     
                                                                           !     "     #     $     %     &     '     (     )     *     ,     -     /     0     1     3     4     5     8     9     :     =     >     ?     @     B     C     D     E     F     G     H     J     K     L     M     N     O     P     Q     R     U     W     X     Z     \     ^     _     `     a     b     c     e     h     i     j     l     m     o     p     q     r     s     t     u     w     x     z     {     |     }     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                         
                                                                                                     "     #     $     &     '     (     -     .     /     0     2     4     5     6     7     8     9     :     ;     <     =     @     A     B     C     D     E     F     G     H     I     K     L     M     N     O     P     Q     S     T     U     V     W     X     Y     Z     [     \     ]     ^     _     `     a     b     d     f     g     h     i     j     k     l     m     n     o     p     q     r     t     u     v     x     y     z     {     |     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                              	                                                                                                     "     #     $     '     )     +     ,     -     .     /     0     2     3     4     5     6     7     8     9     :     ;     >     ?     B     C     D     E     G     H     I     K     L     M     N     O     P     Q     R     S     T     U     W     Y     ]     ^     _     `     a     b     d     e     f     h     i     k     n     o     p     q     s     t     v     w     {     |     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                                   	     
                                                                                                     !     "     #     $     &     (     )     *     +     ,     -     .     /     0     1     2     3     4     5     6     8     9     :     ;     <     ?     @     A     C     D     E     G     H     I     J     K     L     M     N     O     P     R     S     U     V     W     X     Y     Z     [     ]     ^     _     `     a     b     e     f     g     i     j     k     l     m     o     p     q     r     s     v     w     x     y     z     {     |     }     ~     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                               
                                                                                                     !     "     %     &     '     )     +     ,     -     .     /     1     2     3     5     8     9     <     =     >     ?     @     A     B     C     D     E     F     G     H     I     K     L     M     N     P     Q     R     T     U     V     W     Y     Z     [     ]     ^     _     b     c     d     e     f     h     i     k     m     n     o     q     s     t     u     v     w     y     z     {     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                                                                                      $     %     &     (     )     +     ,     -     .     0     1     2     3     5     6     8     9     :     ;     <     =     >     @     A     D     G     H     M     N     O     P     Q     R     S     U     V     W     X     Y     Z     _     b     c     d     e     f     g     h     i     l     m     n     o     p     q     r     s     u     v     w     x     y     z     |     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                          	     
                                                                                                !     #     $     %     &     '     (     *     +     ,     .     /     0     1     2     4     5     6     7     8     9     :     ;     <     =     >     ?     @     A     B     C     D     E     F     G     H     I     J     K     M     N     P     R     S     T     V     W     X     \     ^     a     b     c     e     f     g     h     i     j     k     l     m     n     q     r     t     u     v     w     x     z     {     |     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                    
                                                                                      "     #     $     %     &     )     +     ,     .     0     2     3     5     6     8     :     <     =     ?     @     A     B     D     F     G     H     I     L     M     O     P     R     T     U     V     X     [     ]     ^     _     `     a     b     c     d     e     f     h     i     l     o     p     q     r     s     u     y     z     }     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                         	                                                                                                !     $     %     '     +     ,     -     /     1     2     3     4     5     7     8     9     :     <     ?     @     B     C     D     G     J     K     L     M     N     P     R     S     T     U     W     Y     [     \     ]     ^     _     `     b     c     d     f     h     i     k     l     m     n     o     p     q     r     s     w     x     y     z     {     |     }     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            3     	                                                  	      
                                                                                     !      #      $      %      &      '      *      +      ,      -      /      0      2      3      4      6      7      9      :      ;      <      =      >      A      B      C      D      E      F      H      I      J      K      L      M      N      O      Q      R      S      V      W      Y      Z      [      ]      ^      _      b      d      f      g      h      i      j      l      p      r      s      t      u      x      y      {      |      }      ~            �      �      �      �      �      �      �      �      �     	 �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �      �                                          	     
                                                                                               !     "     %     &     (     *     .     /     0     1     2     3     6     7     9     :     <     =     >     @     A     B     C     D     E     H     I     K     L     M     N     O     Q     R     S     T     X     Y     Z     [     ]     _     `     a     b     c     e     f     g     h     k     l     m     n     o     q     r     s     u     v     x     |     }     ~     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                         	                                                                       !     #     %     '     (     )     +     -     .     /     0     1     2     3     4     5     6     7     8     ;     <     =     >     ?     A     B     D     E     F     G     J     K     L     M     Q     S     T     U     V     W     Y     [     \     ^     _     `     c     d     e     f     g     h     i     j     l     n     o     p     q     r     s     t     u     v     w     y     z     {     }     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                   	     
                                                                                           "     #     $     %     &     (     )     +     ,     -     .     /     1     2     3     5     6     8     :     ;     <     =     >     ?     @     B     C     E     F     G     H     J     K     M     N     O     Q     S     U     V     W     X     Y     Z     [     \     ]     ^     _     `     a     b     c     d     e     h     i     j     l     m     n     o     p     q     t     x     y     z     {     |     }     ~     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                         	                                                                            !     #     $     %     &     '     (     )     +     .     0     1     2     3     4     5     6     7     8     9     :     <     =     >     ?     @     A     B     C     D     F     G     K     L     M     N     O     Q     S     T     U     V     W     X     Y     Z     [     \     ]     ^     _     b     c     d     e     f     i     j     k     l     n     o     p     q     t     u     v     w     x     y     z     {     }     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                               
                                                                                           !     "     #     &     (     *     +     ,     -     /     0     2     3     4     5     6     7     9     ;     <     =     >     ?     @     D     E     F     G     H     I     K     L     M     N     O     P     Q     R     S     V     W     X     [     \     ]     ^     _     `     c     d     f     j     k     m     n     o     s     t     u     v     x     y     z     {     |     }     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                              	     
                                                                                                     !     "     #     %     &     '     )     +     ,     .     0     1     2     3     4     9     :     ;     <     =     >     ?     @     A     B     C     D     E     H     I     J     L     M     N     O     P     Q     R     S     U     V     W     X     Y     Z     [     \     ]     ^     _     `     a     b     c     d     e     g     l     m     o     q     r     t     u     v     w     z     |     }     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                   	     
                                                                                           !     #     $     &     (     +     ,     -     0     1     2     3     4     5     7     9     :     <     >     ?     @     A     B     C     D     E     F     I     J     K     L     M     N     O     Q     R     S     T     U     V     W     X     Y     [     ]     _     `     a     b     c     d     e     f     g     h     j     k     m     o     p     r     t     u     v     y     {     |     }          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                    	                                                                                                "     %     '     (     *     +     ,     .     0     2     3     4     5     6     7     8     9     =     >     ?     @     A     B     C     D     E     F     G     I     J     L     M     N     O     P     R     S     T     V     W     X     Y     Z     [     \     ]     ^     _     `     a     c     d     f     g     h     i     j     l     n     o     p     q     t     u     v     x     z     {     |     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �      	     	     	     	     	     	     	     	     	     		     
	     	     	     	     	     	     	     	     	     	     	     	     	     	      	     !	     $	     %	     '	     )	     +	     -	     .	     0	     2	     4	     5	     6	     7	     9	     :	     ;	     =	     @	     B	     C	     E	     F	     G	     J	     K	     L	     M	     N	     O	     P	     Q	     S	     T	     W	     [	     \	     ]	     ^	     _	     `	     a	     c	     e	     f	     g	     h	     k	     l	     m	     o	     p	     r	     s	     t	     w	     y	     {	     |	     }	     ~	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     �	     
     
     
     
     
     
     
     	
     

     
     
     
     
     
     
     
     
     
     
     
     !
     #
     %
     &
     '
     )
     *
     +
     -
     .
     /
     0
     1
     2
     4
     6
     8
     9
     :
     ;
     <
     =
     ?
     @
     A
     B
     C
     E
     F
     G
     H
     I
     J
     K
     L
     M
     P
     Q
     R
     S
     T
     U
     V
     W
     X
     Y
     Z
     [
     \
     ]
     ^
     _
     `
     b
     c
     d
     e
     f
     g
     h
     i
     j
     k
     l
     m
     n
     o
     p
     s
     t
     u
     x
     z
     {
     |
     }
     ~
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
     �
                          
                                                                                     !     "     #     $     %     '     (     )     *     +     ,     -     .     /     0     3     7     8     :     <     =     >     ?     @     E     H     J     K     M     N     O     Q     R     T     U     X     Z     ]     _     `     c     e     g     h     i     k     m     n     o     r     s     t     u     v     w     y     z     {     }     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                               	     
                                                                           !     "     #     $     %     &     '     (     )     *     ,     -     /     0     1     3     4     5     8     9     :     =     >     ?     @     B     C     D     E     F     G     H     J     K     L     M     N     O     P     Q     R     U     W     X     Z     \     ^     _     `     a     b     c     e     h     i     j     l     m     o     p     q     r     s     t     u     w     x     z     {     |     }     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                         
                                                                                                     "     #     $     &     '     (     -     .     /     0     2     4     5     6     7     8     9     :     ;     <     =     @     A     B     C     D     E     F     G     H     I     K     L     M     N     O     P     Q     S     T     U     V     W     X     Y     Z     [     \     ]     ^     _     `     a     b     d     f     g     h     i     j     k     l     m     n     o     p     q     r     t     u     v     x     y     z     {     |     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                              	                                                                                                     "     #     $     '     )     +     ,     -     .     /     0     2     3     4     5     6     7     8     9     :     ;     >     ?     B     C     D     E     G     H     I     K     L     M     N     O     P     Q     R     S     T     U     W     Y     ]     ^     _     `     a     b     d     e     f     h     i     k     n     o     p     q     s     t     v     w     {     |     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                                   	     
                                                                                                     !     "     #     $     &     (     )     *     +     ,     -     .     /     0     1     2     3     4     5     6     8     9     :     ;     <     ?     @     A     C     D     E     G     H     I     J     K     L     M     N     O     P     R     S     U     V     W     X     Y     Z     [     ]     ^     _     `     a     b     e     f     g     i     j     k     l     m     o     p     q     r     s     v     w     x     y     z     {     |     }     ~     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                               
                                                                                                     !     "     %     &     '     )     +     ,     -     .     /     1     2     3     5     8     9     <     =     >     ?     @     A     B     C     D     E     F     G     H     I     K     L     M     N     P     Q     R     T     U     V     W     Y     Z     [     ]     ^     _     b     c     d     e     f     h     i     k     m     n     o     q     s     t     u     v     w     y     z     {     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                                                                                      $     %     &     (     )     +     ,     -     .     0     1     2     3     5     6     8     9     :     ;     <     =     >     @     A     D     G     H     M     N     O     P     Q     R     S     U     V     W     X     Y     Z     _     b     c     d     e     f     g     h     i     l     m     n     o     p     q     r     s     u     v     w     x     y     z     |     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                          	     
                                                                                                !     #     $     %     &     '     (     *     +     ,     .     /     0     1     2     4     5     6     7     8     9     :     ;     <     =     >     ?     @     A     B     C     D     E     F     G     H     I     J     K     M     N     P     R     S     T     V     W     X     \     ^     a     b     c     e     f     g     h     i     j     k     l     m     n     q     r     t     u     v     w     x     z     {     |     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                    
                                                                                      "     #     $     %     &     )     +     ,     .     0     2     3     5     6     8     :     <     =     ?     @     A     B     D     F     G     H     I     L     M     O     P     R     T     U     V     X     [     ]     ^     _     `     a     b     c     d     e     f     h     i     l     o     p     q     r     s     u     y     z     }     ~          �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                         	                                                                                                !     $     %     '     +     ,     -     /     1     2     3     4     5     7     8     9     :     <     ?     @     B     C     D     G     J     K     L     M     N     P     R     S     T     U     W     Y     [     \     ]     ^     _     `     b     c     d     f     h     i     k     l     m     n     o     p     q     r     s     w     x     y     z     {     |     }     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            4  �   	             (      1      �      �      4     �     �     �          ,     R     9     �     �     �          �     �     �     �     e     �     h     �               *     K     Q     U     �     z	     �	     �	     
     ,
     7
     �
     [     \     q     �     �     �     �     %     ,     w     �     
     &     *     �     �     �     �     �     �          '     k     �     �     O     ~     �     -     1     7     �     �     �     *     j     �     �     �     �     �                                                                                                                                                                                                                                                                                                                                                                                            5  �   	       `      z      �      �      #     �     �     �     �     
          $     N     �     �     	     -     �     �     r     �     �          w     �     �     �     �     G     �     \     l     �     �     �     �     M	     d	               B     V     +     v     �     '     �     �     �     �     0     4     g     �     !     g     �     �     �     3     �     !     E     {     �     �          .     F     �                                                                                                                                                                                                                                                                                                                                                                                                                                                                            6  �   	             �      �      J     �     ]     �     �     '     A     v     �          �     �     �     J     p     �     �     �     K     f          �               ;     }     �     	     �	     (
     N
     �
     �
     �
     �
     q     �               c     �     �          �     �          J     �     �     �     �     �     *     4     T     �     �     �          o     �     	          j     �     �     �     H     �     �                                                                                                                                                                                                                                                                                                                                                                                                                                                    7  @   	             a      �      j     �     �     �          �     �     P     �     �     �     P     �     �     �     �          �     '     n     �     �     �          	     �	     �	     "
     7
     �
     �
     q     �     �     �     <     �     �     �          �          6     O     a     F     d     �          Z     �     �     R     �     �     �     �                            8     	       �      �     �     r     k     &      
     q     �     �     u     `     U     �     A    9     	 .      �     �     �      
     
     �
     q     �     �     O     �     �                            :  @   	 7      �      �     "     �          #     (     M     d     z     �          <     �     �          $          3     �     �     �	     �	     �
     Q     h     U     v     �     �     �                    "          b     y     >     ?     �     	     2     B                                                                                                                                                            ;      	 ?           t     �     �               �          �     �	     �
     W     d     �     �     �     Y                                                                                                                    <     	 T      �     f     s          �     �     �     �     �          �     t                            =     	 a      �      *     b     �     	     "
     q                                                                 >  @   	 h      �     c     d     /     �     �     �     �     ^     u     �     �     �     �     3     �     �          �     B	     s	     �
     �
     �
     �          �     �     :     �     y     �          �     �     �     �           C     �                                                                                                                                                                                            ?      	 k      v      �      �      -     "     �     �     (     �     *	     �
     F     j     �     d     �     t     O          �     �                                                                                    @  @   	 v      �      8     p     �     R     �     �     �     �     �     �     (     h     �          6     �     �     *	     /	     �	     �
     	     ^     f     q     x     I     �     �     �     �          %     e     �     �     F     V     �     d     �     �     O     |     �          k     t    	 O     [     �          �     X     �                                                            A     	 �     	 q     ]     n     �     �     �     S     �          �                                            B      	 �      �      �     s     `     7     �     �     �          |      	     �	     �	     �     �     W     �          #     Z                                                                                            C     	 �      -          �     �     �	     d     �    D      	 �      �           �               `     c          u     �
     f     �     �     S    	 X     �                                                                                                                            E     	 �      R     �          6     x                    F     	 �      R     �          6     x     �     d     �                                                            G     	 �      -     E     �     �     �     d     �     �     �     �               [    
             H      	 �      R     �          �          %     6    
 �     �     �	     �	     x          "     �     Y                                                                                                                            I     	      �          �     	     �
     W     �     �                                                            J  @   	      �                �     �           �     m     �     C     �     =     �     r     8	     �	     �
     �
     R     �    
 !     T     #     a     �     B     C     I     }     ]     p     \     �     I     u                                                                                                                                                                                                                                    K     	     	 �                 L     	 F     �     �     �     �     �          �	     q     �     �     :     O                            M  �   	 F     �     �                �     �     �     �     �           �     m     �     �     �     '     C     �     �     �     )          /     r     "	     &	     8	     I	     �	     �	     
    
 �
     �
     �
     j    
 q     �          6     �     �          R     �     �     !     x     #     :     J     O     j     �     �     �          }     ]     }     �     �     *     \     �     �     �     �                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    N     	 F     �     �     �     �     �     )          �	     q     �     O     }                            O     	 F          �     �     )                         P     	 G     �                    Q      	 \     �     �     !          �     �     q     �     �     �     �     3	     �	     D     �     �     �     �     J     s     �     �     �     7     �     �     ;     �     �                    R     	 i     (     Y     �    S     	 i     �     �     /     �     \     (     �     q     ?     �     �                                    T     	 j     q                    U     	 t     1     �            V     		 x     �     �     �     �                         W     	      �     �     -     V	     �     >     N     �                                                            X     	 �     �     q     �     �     O     :            Y     	 �     �     �     (     �     
     S     �     �          �     g     (                            Z      	 �     m     n     �          *     �     �     �
          �     @     #     �     1     Y     �                                                                                                                            [     	 �     �     4     q     �     �     �     O    \     	 �     �     P     &     �	     ]                    ]     	 �     �     �     �     �    	      g     �    ^     	 �     �     #      
           q     J     u     O     `     �                                            _     	 �     q     �     F                                 `     	 �     x     �     7
     q     �     W            a     	 *     q                    b     	 _     �                    c     	 �     �     �
     q    d     	 �     �    	       c     *     �     H            e     	 �     �     �            f     	 �     	     -    	 0     M	     3          �    g     	      �     p     h    h     	      )     n     �    i     	 C          �    	 �     @                            j     	 �     �     �            k     	 �     �                    l     	 �                         m     	 K     �    	 B         n     	 `     z                    o     	 �     �     w
     q     �     �     �     O     ;                                                            p     	 �     �     <     u	     �	     �
     �     �     �     g                                                    q     	 �      
                    r     	 �     �     "	     j     �     q     ?     j     �                                                         s     	 �     c
          O     b     !                    t     	 F                            u     	 �     q     �     O     Q                            v     	 �     �     �            w     	 �     �     �            x     	                              y     	                              z     	                              {     	                          |     	 �     q                 }     	 �     Y                    ~     	 �     q          �     �                                 	 2     �     N	     �     '     �     �              
 %     �                                            �     	 �     N	     �     �               %     �    �     	 	     q                    �     	 *	     �                    �     	 �	     �          �     �     �                    �     	 �
                            �     	 Q     �     �            �     	 �                            �     	 c                            �     	 c                            �     	 �     �                    �     	 �                            �     	 d                            �     	 W                            �     	 �                            �     	 �                            �     	                             �     	 _                            �     	 �                            �     	 �                            �     	 �                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    �      �[mp[Uz~eI��	D	ג��� �ao��I܆8���,t#(�Nh��\�ʶ�#+���!��?:����0���ӹ|ˏvg��t�U�m��v{iک:����+]�7!(�f��{�y��u��=�Ⱦ??�	�� �����Y`������ѧ��B���N4$J��m���n��=���^"�y��_n�:�˻�=>+H�r��o�|� ���~�o����A�|sx�I��|��@��@?rn�����O�� ��o~��o���G��v�·�o���)~����܄���I���DY������X����;���O�}����p��ޝ�����]�p��Ã/<��֗_x�����;v�۞{񅭇=K�v�����?����������/���!�ݶ��������S�3�d�����O{v�۽��w=>40�����/�iߞ޾��;h�~�o��b��ٻV�7��o�����7��{vR����{�q�;�9"$In}���~-yor��C/>�J�s���z�>������OJ�,�A�����z� =y`g��ۻǹe�R����\�����������ttnNut�$�tt>�H���S�ڥ���۔�T�O����\�\�o7�F+��j��������ϙ��f�|ar�ձ��3����g�sggg��\&�ŋ7O����L&g^;],���c�����'_�=6a�N���
�HR|;�܉K~�y&.���
��ѱ���&���:���Y�E83���gp�)�"?�,L��I4.N�L�D�"7y{�ߞQ�D�����s3���<���f�	ߝ��!�h��,��&O�NLLB@��`���<52~�P��@�*ΚcS����ߜ���6Q����sL�ǊE����⾧�1��p�=�N��ɂ9>yr�U���p9w/��9=U��S܄�:~���c%�!Lk�bǋ��s���G�X�1 �d�r�a�,?5:�V�ͣ����/�𒗡�9rr&+.'�,��tabb��������#'���������
�7� .���x��
yXuά���\������a��Ys9ǖ�]�r9u�r��3���s��s�c�s��^α��K�
�lv�e�r�׹��02U��"_��eZZz�_&�eڔ6?}Z���^�Յ	\�ŹL�����n:_�����n�G���# ���/�lK� �$�h����$�dԊ,ۊ6��&�A����U���[� ��.�7��ȾH�!�a����`�D�B�	���D7#�݌<v�M6 ��$���r@��D�'�>�Ot(!���w��D���[�ӭ|� 2ܶx�	�����2�Y���~9�Z:�� ���3 �ܱ@�;��;��W��
��<��L1�{ �1������+1ƪ� x^�W��*<���^�Ot�����t�}�C����>�];do��%}�A3�4 ���qc&`�dH`��I`�$t��n��M��V�^w��w��]�����n�q7讁��@k����m��8�f ��}h{�އ�k�v-讅n�A��'������~�}?t� �~ 2�_�Ao�� �� �h��)�Ⱥ�o��`�A�A�� dJ��dL�F
<u�v'�������97B���}d�}<�<�A_�N�B����^~��{�'&�)�����B����uR�|a�V�dJ\��I��C� 3�7)g��"f.� �Vh"��X\�L@�N`�)�T�Eq�%XL-��L��e�� �ޏY��-���v�c<�7�_4e}V�B��f�:-�^���g>"���Q �(���b�|�d�_H!r�(hZ�t .Q)�����@�� O����6m.�(c[d1�~z�"�� ��_Y]3��E���AD��ˎ���f/���BJ��YZm��7�A$q�S��ʬ�z�����s��%K�����k��������j������#�Up�yI��w�wt$YA�yXAm�sR	���͚���HJ�� �*�_���6�ǆ�2`~�%�A�>������Lg�i�g#3������hi�G֐��}i�\,KDU�1M�0�KX��z m.��(��2y�Z��E��?�I�]���pO�ǔ�B�1e�6��'�Oփ/г��x_$�<���N�@u�ø).�������%˺��F�T;q�����}G������N����E&��GG�,&H�P~ƈI��ik9��]S��~��^6R�W~f���;U;����jrLy�O�|��_W��M��u�*I�@\Q�DI~e��U?�m��G0`��[eN������q�g�s�(��*�zu̸�$��n\b�^<����Uk{�-N�v�t>�8O1H+��!��e������p��� G�$M���4Mf{��I;2V%y�6�+���#oу�a`��C��A`?��t�P^�m@
���y���APƈj�7#��E�hZT�J�Y�Q�9nQJ�@I`���+:v����F� ���%��V�
D�6TaC $ �� CW\žE���"�3��^�ɱ�/������������J�K�#!�Zϙk�mA���U���Ddr�:���I|� �JOv��� 8:����b������\�U�:n)e����J�P���
,9�y.~� Y'$.�U��=P���(L4-Wz�w/�Pp�i�W�/`I;q��J^�k�~��ȌZA3z�@�=j-�3�K�)|A��E�e�BiP�U �SLRYJ!q���y�<h���S%�NQ #)
�4��=�,����:��<-�(��+��l�TE��
�w�oC٠�1���
��z��`R��PTT�f�Kg���-������}������_����%��+,INL�ᢊo���	5��2�	�+8q���#�ƈ�b����_,������v�Q&�.�r�I\0+~�Mk�Q�YĠ]?H �@�ʶTa3�����L��S�\�����2%@':����r�<kSH���S9?.��E1��¤! F�p�O�H�M���i�|����- 1;� ����������:��L{�w�wJ�N�X�5�v��ڀV�LF���B&� ���S��t�=�0�9�$�ZT+^��z�iF�j�90����_�w��$B��~���'�}��2.�*fbxgI_�+�h�C��uhq�k"�R'YT����שW#3�_a������	��a� V���)�4tl亪D�km��~�k#
��a	5�W��%(u���:����f��� �-�����Q`������5�!Gْi�}V��<c_���M�u[w��#�0f�p�e����\�r�ՊA5|��6�u�%�k�8I6#c�XMa��Kݥ+�Bn�/�e����c^CV-���3�xZ�p�瘛 :�˜��L^���\���䑟xmUg�.<3�a�ÊY��������x�y%Yˎ�����L�J)�Һɪ�{}��G$�����w5�w�3���-S�7�u�^l�m�'{��^���ښ��52�GȘ_�-?z���ĩF�`0g�d:��vf�F�ڹ��*m�s��J~�\����r���l֒2�p���8*��Wk�v(�+��W\���9��>����2�e�q�8�J��~���(y}�����݃�O>5T]�/��5�%��y.����u���i�˪���Kgn{�=��Rd�0e�m8�t���|���P^PĬ�ވ�ܖ�]����1��5���y���&%�aӄ�yυ�J�2d��=�(�S*w+=q�R͓4,1�k/�~^�8�^3C����_��ڱf����g��c��R�J�a����٘\������BW�I���wʨ�Ξo�1�<������s�P_K����%���5�WL�[�w������"o�`��;Ƈ��x�S���\�#y}�<'�����^���-)�S��������b����������7%�����J��� z��`�z�%"�N����@�&��ய�5C��^pj�n����Q_��̟��7�'��.��Zәr��1�F�(6,c�r,c�;%�����1jF������_� l�qb>�ˤ�|�MS_k�9EG���g�v�bG(M��ў�q�üŀN�%K�"����Y�^;X��~⌃뺒<�x͒爯X�nIz��_��+ۤзm�%:�0۞��J���N�i(�]����9�8Fr`�x�|Ğ��mʳKH�8�Xӌ�f�8n2e{'�r|�8`
	�tiR1�H�k�3R=+ ��é=��sdi��8��s��#1,�0�X	�ʠ*:Y�.��JT�{����T�Y��G��a�<e�s��-Q*)������9>�}���p��+��[E| ��8��b�n�9��Ӕ¢c�'�'�&���YHa�%r�P
Z_O3��/���gZb?^ĵ��[�6�n>��GR�4|�^���z�PŢh�DA�4xC�X�	|��E,��5��YS�9B�eC�31�e�i*�9�ͯ�5�,@����@_u�����ӏ$傘'w�i��:h6m��
��aWdu)MA��[����2`p��>D�c�9.��A+��9�Q?e�2�5��'�����"2V��f��t���u����E?�K�_��b�ɴ��Z�W��M=b(�}	j>}�l�ǚO�k'ͦ}5督�<��yg}l����l�R�b-u�{�Ϧ��MY������L�!���H��#A����鼷��/����`}t�'��%^�q O�j��%b��]D�)q���,!�HX h�M|fUg�q��zmD���@3Ϸ��ͦ�q1���9��������J/��:��ge�1����$��b+@P�,>����8��~���A߂\�W~��"ξd�#&�ٿ֥�j�7�،:��){�ky�b��E^~�0-k�ֿ�=��޵Щ�ˆ�a=�T�F����6��@?���)cd�1y�+����V��k�E@l�,�����l�pQSY��i)O�gl�QZ^�R��xo�����Z�r��"��Z���AYN��l������Ҫ_J6J���#�,ۡ�������w|��+dﳬrZ�/p|�����\�&fڍ��y�{ôl���9�_-���
Z3�FgI�l�����X7�>��\������v�o�43c��d^|#.�����K���ƍ��yٸaZ6n�V�m��cM��s@�w���x�Τ����[��a�܋��!�`�V�����n��1�-(Jmt+�F�h9�Nw�
�_W�*�̴�.KP�V�]t7��{�^����:�����A�Aح�6�&z��G��ߖ�Q�|w�w7�P/m�>�F���v�v�?�?�]���A�Cߦ�����q�=AO�~�.=EOӟ������.�O��wrn�VTa��Ň��%�A� AA��!6v�c؁� sf��{<�g���9n/IV��dVf�iV��4���Q/�C]襨���|�A�ַΜ�$n�1k������}�2��kC�
mt�E�%G�Rd�r(QaS� ˰+��K�*� >��x��Q��cX�ux��6�m�Il�S؄����f<�-x[�/`;^���K؅��
^�n��kxo�M��[؇�xp��]����>�!�G8��q�4��z���,$g�7\�H+�o,���I�d�A�3�s�겻�ٌ�a�Κu�����I�����7�:I�_LK���ABy�.%}.���~N�$ztp�u�u+�;�v�Wڡ�l���߼.&�Ȁ�c��C�v72M;�J�sI{_�}��J�k�}�3��w���-��F����I������1i��R�;�ϳ:sg���[i�볿Q�b�g��kgо7~?�Q���C��}�q���G�J,��XX�_�o��żS1qh�ƍ8�ƶ�Ģ����d�)S1r1�'����vռ��مձ�wE��Մ����,8^e_�.����qL��#�S¾�����GB_�]
�_�/q�N�' ��|��;��p|:��i�o\1º;�>�;l�s>a�s��8�.W#�2¶9ڗ\���a�0q�!���!{ї�����urw���9����ރ��8�w��!k�>�D��Ӎ���&B�8�	}��?�nr��/�g�+����'�o��pNع�\�����a�&r�������]�_W�8뾴����{�|A�%���N��~��=�л�p�y��]I�#���"�������a?�V��l l�G{��}�a�R{���I��]O�O�ϣm����	m�����\Chۧm�s���жO�>��3>}�ӶO�>m��m��ߺ}��>�|���\����\��E8��q"������~*��a�0Qe����UoL�E�IeIB���C��zLA�p��D��*MT���_���b��*f�^���U�.-�"IPt�L��T���Pvsť6�r��I�"^�BMRG�BӘ�a�d)o�bI%�(�&� A'WͲv�(c��=D��A8�JӦ1&����t��8�<�z�҈n	�\��}&��te-��a���H��(�Ja��=�0����ccy6�R]V�B�(V9c��a��A�Gm:���S�I�z�4;�:q$iVN�-W�X�RzA��UG�KG�e0̌aQ�����[V�B��]$���]�tL���h?�}��b�zl~��R?[�T�<��f�$m1iou'0�jI`ZR������h�k[�wZ��ek�4$�C�<�P���EfXd�2õ�P��]bnD�GD|�!>bj�Gk�O�n8*���:�P�u��E�,O�Qy�cv,)��)�AC7�A]D`�p�M�A��e�PV�V,2������QtC*�2�D<k�gV�֊��X�'T�X�b�P�j��d��	����{���"��yN� ���(M                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  �      �[[lWz>�g�p��MNh��n���v�QM�Ve�V�X��܊���f�u"��҉ �.6�Y��ؔo0�>�C�(�>,��1�X�C�E�lFPQ�C���b� ���?�9�E:�H��o8�3��o���s�(��]��B�&�B��-���u����~��Y\,W�7a�"��W���BlT�����f!l�m��ܡ���|�����e��O�<@'Ok�XO'}�v:2���O������>9I����o����?���߀�Gw�щ	����2p���B�����x5N�@'�B-xt�
�a:yx�}'����89���e����m���~e���ų���m}yh[�s��g���=���{�6o�{6��1��{۠���/�m���m�^ѽi�����[{�����R�֡����������ށ�����oz�����ӷm�xNt�л�{s��C�l�ށ�v�n��}���tg�Aﶞ�M�f����>�Er-^�'�v���J�,���ݳ��n�ӿ���a�p���=���`��]�%::��O�q]Bj(1p���ݯH���kxvx�΃�_y2ѽwob�t �c����ߠ�(YD��#�iϫ{�ܛ��whO��ݯDS��g����Ķ����rⵝ�"�6�� /��г��I��}`�����������=��BX�΋J;�o�z�P�]*���A{;���}����k��I�s��qT6j�PN�3����7)۪1�q` ߩTp��J����D����+�|�?9�{�xڶǊc����i���b�b���$�8��'OO�?;Y,z�GƏ�pt�8}OOۓǋ�����?�Ù=~���&��a�X=��{����gtvl�8e��(N�8��r�qb�P,����<����F�"X��}��lyF&�у�t��!V_����iuvd�z9Y�"ߝ8O����kj:;	N��@�3��bq�P�erLW�hg %坲'��ٙ�Ta���1(�P���Nْ
D�*L��a\��T���ih�dCc�,�@�Ha
�Iy(��4�ѩ�4~f�I��J�dc-��K}�X|���ON��4�~pz������)���ctx��7N<9C��D�x��q�P��>�.ߤ��qҮ>@%'�'�B�v�p����>��rF�`�I/����-΂�8����N��`��	"8�'s_PTNi�ԇ3t(V�nd��ҳ��;�4m� �O���i������<�P�B��㍈�1�
�P,T󵣆�VJ��/��B��/r[
@v��6�~�
@�� r�������w^�V��j��E�o���w���� },�o!nE�"���{dX@	���@�z�軵@߭qʋ���m�}[	�l�~���ż��
�]q�T�۟ ����{��{��й�wl��'�w&�� d�2������8���?�D�pO�W!��k�|����i�$ �_�B�{A�^���<FA/����3
����*�{��A�X �1�G�8d���8t�.��	ȗ@�� ��s+�6�������_���� �z }=���a����C��a=CƇ��G@�����>h<<
�=
]?�>����������q������	FO����^�q��On`����S��)�M�IȔ�yd�-:Ц�VCo�a���q���7ր�Z�r��O�ϧ��Ӱ�3��38|�_�`�u��:��-�[��N�݉��<�~G��S��`|_[V���Wӡq�!�Cԇ6V(�?8�()Pa|�b֩�]���<��'�'j�Wl��������,�����}
;mŠBL�g1T���䍣���t4�A�.��W `m>�Yw�0�!y�$��-�s�0��.E%���{���I-
axd�C+�Ή/3��TH�������@�\�7>*8�Fp��$<�G�! 6h��BN,��Y_[K"��P�m�K#��66��[��_N��)y���;�;e��d��"���,$�>"��r�N~Y���NQţ��k����٪�[֖W�Xw����h.u�)/14H���sx)�����.�Л���'����I4�#�H�n[��ѯ#�h��Àq�&^� ������HK�GʆG&u)?��b��o��ќpD��z	υj'3���]5Ӯj�f~�{����A���
�b���R@֪�IŬ0�BY�'����.����zX�(�����8;��
�A��d)=@���Sƍx������)�;,6�Kی|�����3�4��Osj�8�ta�a/Ā��b8�o�Xi��Ru�J� �/1��oh�N��$��X�s�	�?��V�W��У.jr����N:�4��������e�l�aBԘU9Pɟ���d7�᪙�ȱӥB��_Z"�X�� :2.S͉/�2��W�ٹ�c��mLu9"j�H�s�O�n�k�N"9֑����4�W_�T�(re9�h, 	9�0�>�w��]�
��x�)�rdF!���J�)H��+�����'D�����J�@֊���� ��}��i�ڍ��?�7��BLC��q/�lR��+�����'��#, ��C�!<��\��f��G2�s}F<̓�GS�\�_����`�1��0�T&�K\�C,Ȃ�B$p�;D�.�T��|;z����N�{5��&�!%u�,��@w�n�`����Jϫ8}�,�׀����l'�1���ҏ|��������ؘ7ʱ�KA��
^����)�.���Y_�����%�Ћ1�t�j3��K��:�����"s��a�l��c�8�**v�N!�0��g�>-s9�NȊ�(0�Ō�Ì��U z4v� c�A���p`_�ex ڛ�0.0Q�t2b`�U�k\A%?_.@����r�÷��X��F�@�gK���V#�o�2�`2oT|�Q|��ʴ9��Xw�cC���[q�jnU ���y���s�sv\����Ox���C��iγ��@�EՇL�C�)bU�@N#u��8�xI�a���z�䒉�dg�*��&��_g��_��.3fg���L�9Bݰ�ǜ��|@�L���~��Z]^?�C9U�Q%���fI��?)�[a�]�sHW1��1�g#�F�".�Y���w>^� P�[:�Z�*��_2���-�#��Q$y����]�|�p�9\*c�zȕ�͡�������H��-10FxL��&�1:5��eҟɲѼ��L�ed�1�cE{�w
&tA�E�Z����:A�唲��^� ߒ�����0���C��~T�u3�Aun�������7VǗ�Z�A+�T�
�
�?&5J�,n����Ih%2�s)Y���P�5<%kT�A<���&���c���\T�%�{�i�~��1!W8�����W�r)X��k�f��]�@�+��%�G��Ź.8gN�/\gCĩ�i��
����z���F<2�B����� �'.�F����o�ڛ���ϕ~h��i�j�E1P�T��sd@ϫ�;�r��0W7���61fQ�~��X;YH�TrhYb��(������D�kT�7�%Ŧ�Ͷ���74��|1���U����W��1Ҩ�!��\#��V�T뚄��>�4
&�����ǐ�>?E�i��l�/L������s��e�e豔W�2ǿ�A��%f������籠�$�2b���Z� FG��rΓk]y[��7�q�n|Pn��\�g�Z����Ì��3����J9�2��-虐S���� �5ҵд��"mFv�C��'珩���{�1��Z�ړ� sq	����E\px�����m�K[�]U��[Ժ����dL�)V{�������$��)]���?Ga7�7�O��v�Jզ�_�?�D���_�Dky�Fu��=�`J��y5�N���L�&�������E�م8�Jq>���eO�g��+�N�g��[h�&��U?��J������)
������e[����+B�QV�:K�qRv��D�=Yǁ�l�sj�/]4���6����r�����.��z���?#
�<\�KYg���~��O�U ׹�Z��el��Y��4F̀:f��S�H�h�jN��ZȨ���ױ�/!D��
�⪸Wf?�)�VW�%�ڰ��P��M�Z=O1f<]GҊ�%}O�G��< ^ڠ�W��IYӥxl��)��9�Ε!"��ќA�7��*A�M(ު�����o�{m>[��7�=�,T��Eą��Oy��E�Y�����̄'x�U�w� �d�>���0����R���1�Lp����Y�P�\=qQ\	GB�)�a�/�͉�eO���l���W;[3,��, 	t��g\։��3x������^ �������7�֑�a����n���I��ИE.=��yKl��D�w%*��\��D1��b��,q��,�힜���Z�iީl�=鍐��(����z���vi�����۰����᷿ұ��z���Qؘ��޲&�+;�q��	�A��=�ç�����m7K��!�`Xʷ��Zj��F\�Z�o��/��o+���/��Td�}�s��@��� �%SC�����}�"R_��SV&
i}�|�P_���#О(���{�F�-�N��D�"��B��à�m4��x�Z�c����e��Ɨ%O����|$���V0��=��hkEM�X~��>B<9�G�m� ��:Y��e _����B�(购A��zR������G�h��[#,��8 �v��%�[��"��������G1{��̙w���dD��k?�<����pk�h�a��K�_m�%�}����=͊�[�ڋ�c��i����	."ٵ�����ri�2d����H��L��E��<N`�&��[�>HOmxp���K�}-���*��}�
8���s�(�Gّ�WM
��FQ���q���=����=?9n���c��fcc���ŲN^7��eJ0�>V�	����#�\��9_K�fu?z��^���F��f�C�/R�1ʵ��7���1'��Y�>�{�΂=�4�w���=t��{��s�Д���$|�$����>O����W^ڽ�f�����}�J͗����U[~���$9(���:�͠����-��r>�R�7]����j�E�@���B�u��>�o�Ds)sG/��R��b��V
�^Vt�G����c�뀿���K4v��j���v��,��MX�I���g����G�	�ܜ~Ŷ�/�}힬Z_�{�_�GN�1��RW��� �^}cb�Ծ�*_��N�L!���^�\���(Й ��H`l����� �suNݮ��=9*��e�4/f�1����h/����N��o�t�sB�M�t-=�-}�iD�������$p\]/��Y��랬�"]�Zȏ���rj�����-��/ ;6l��_S���n���{9�����汳��i���F>���]�^m]i�47��B4,��*����v�qͼ���sQ��M���h&Duo�����u�4��E�C3q3��-�.��/h����A��2�#��ea��}L�����y�����xW���:2'�c �y��a���?�Kd<P�����u"�\��?���fch147���&��1���q�	���RГ���.=�?�FS�7�=G���ٍ����C�Bܾ��bo����\.#r�7�Am�������v|5i��@ߩ���׼�����H����j�E�L�Z\�X����(6,���uUc	���v�,F�"���>0""jEA�R^a�aXE���f�ٞ��>���0("�^x�x^�}4�E_|0Q����迺z�!�!>�&�������u�no������n��������Uۺ�̞er��>Vs˧�U��q��|����������_�Wm˥����&�n�p��Gc �b���K�!8Cq<�a8���ĉ�d
q
��(���1g�L��X��q8�`<&�\L�$L�L�y8P�i��9.�%��s\	�af��0sЎ�1W`�W�*,�B,B'��b,�R\�k��a9�?��g��e8p!QA5xX�.��#@ȑڍ1���Jf��UX�'���7��ŭ�uކu��qw��p'��f܍-�[q/��>܏� ��!<�G�(v�1<�'�$��N<�g�,���x/b^��؍W�*^��xob�b���x�⽢?���K�p��+���G��C���Ɠ���;�, �H5_�S���%�Z��Bŕ�c���$8�1�O>"��/�WD���c>��L~!����(�Urc��&��� ºl��'y�m0��a�2�p�1����M&��d6YH��TH�� >	�kD$!=���"�yk���A>I��z��p�h���6�-���52�����&��� �̫Oɗ�ξ2�%�,j`�q�D�s�L���d.a~L��d�M��d�̛sc2���0�^dg����1�#����+'u���5��"�c�#S��JdYL��%I7a?��ۭl������Y̿��Y��n��J�i�k}C~ l��ض:m al���ǒ	dal���9dal��m��f.ljo3���6c��	cۻ��Y���P_�s�]��=����3\Y��85���!	������4L�[�����b��}�v92H 꼊E�j����DCD2�e%�W�IYq"#/�B�Oc8a�.Pk6j2P�y���q�d"$��!�Z$�Ԇi���#{��e}dVh���	�0�����|ǐݩ�Q��`X�N��.��6�H8]2��T楮j~��}��9^�u��KY�0���`�e۠J�y�Hj��x�+ȗ��eE)�3p҈�;M4�X9
�d�ʊ����z2b�T6���Fn�Bf�VS��e=���ê�?���E��P�E]8�*PVU�T�Y���i��H��$�4������Ԩ��@� +ӑ.��
/V�����˫��G*ݼ�	��C�7�dB�tbJ�%���/{Q�Җ
uJ�ҲԆ}Uj��mڹ�Ź��j�6�ڦ�Ŧ��iKj���uh�m��bޑ^u�V��7ѡ�a�v�Ԯ�-����R��Z�ʨ�1[�c���E���aEQ��do}2H�,��lq����m<m��x����j�P��-�anPx�^��nhR�jǴ�1-<���$�Y�F�/>�s������R                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        �      �[pT�y�wW�H<+h� c��
?Xbْ*	P*K�$0؉�X PH l��֕�@H�'v
�㺩�$���$m�<f����qR7��S�]��qgRf]gR�&l��<�޽���m����y��?�����u57����	����ۭ�ہ@
Q
���5Կ�L��7�5 �S��h�O���z��T~�4�/�j�)�2�O)^��x� ��Dp''@��8��N�m�3�͉oI�?�#��4��_��&'�x��f�Ɖ�p���A�+��:�-N��='~�M�^��{�N�D��.�yv�,_���'��x��H|y}ͦ��T��������ʪ��ե�WP��=���+*7ll�E��������*�n�:��hx���a���nݿg�n*-/o�o�ZU!K��rKEUc}�CT[SY� �u�5U�*k���3[������z�R�抺��b*�XZ��*6T�7�8���e5��o}���m;�Z�[�����q�� mщ��eq3,���Z'��Z��oٹ�oE�m��u�;W�s�O��?�~`Ǟv_�ަ��m���ر}��t�n_wj���h߱�	.G)�����[v�ض�W���=;�@SI��uobbT]�PY���ٶ�1j,�(6��q}Muϥ�j��U���u5��*����[�no=��c��6�Y���
�[�(`Ơ��҆���Z�VɃJp����ǃS��M�,*�RPW ���`�]�A�_�����5�K����)��J˕�)��3���%���D�,�g�戚�����y����9>bt��Џ�Ϫ������x�H�xt��Fw��B�t=�u�{��B�0�3��Ј�}"�R�}�T��� ��t����¸���cd��!<8eŲ'�̟�94�'#�}A�:���=�a��ZAE�` �x��C�}�B�x�g����{��ɜ�=��
R�|���D����e��N�{�b�b� :8*��PƤd���amdT��ԉ>p�}tD�B'��r9vl�2:�"�?ơ����� ��zt�~�>}Z k=V��������)z&04��9�����F���Р����~�T�q�W��}=�y��<����ѓ�F��ɡ�f��GF�cx$$�xvYٮA�A�2̍G����3�ncr��a��^���z�:�BV�5h����0�6�@$����X�S=!��xH�z8��z{O����чG?��q�"�ˊ�!��T
l�4�����:�~�mk�k�"��{` _8�ƈ<�<���d�T��O��x��/�zS� ԧ�&�$J��iw���˨"���~�h�Lk N�`S������$�� ^d� '2.`qC��;}g��L���qf����=�gb�L�=<e�M�R J�d��,Л^f����uv  ���mx����^~�e���9���悇����oy�h��Czb�� b��A <��2���ߋ�a6�>�Q�}d�ނU t� 2X�o!�X�Ak!t����x9�7��Ay����9��"�|/¸�@s1��</Ƙ��[.�h�{��}��>�҇�灯<�-}��g	�,���<`�%#m�1~>��G�|�c)�2_�~K�&Z�-���A��o9��Q��uk-��W@�+� ��m������v�;d���+A�
�Z��P_��ը_��ը��o�9�"�q�� �Sx�8`������1	?$��Kd-��3��(�'@GX�#^��)���#�1����s1�uW��aM��p���6� ���4�B��	���
ʸ� �Z�u1��g�Go�ҋP�y��h�ͳ���1�i��K���A�"���I�^��[:M�s;n�	�	�řGO�Į�$(���)^E�T�\����~"���g)AES��~a��B�鼓��g��=�A�n�\Sm�����m�`��Lw �	�ᵠ�ޡ�3}87EcNX�ġ�mb'�ڝ�KA�I;��Q̫D�ѐ4�60-��dٟ�N�� \��5�E��c�%�|�	(��O۱F.ʊ�xyG�<c|�|0�*>�p�)}"�d�t���������
�n�v��<\��i��Z����a�;K��=/�)>t�v#�}	��Ŧ�o�&)ٙ
}t-��>����}���
˵��f�+Rs�:n�m��G���MF��}�����=����>خ�kO�mڇ��L�)�Gb��3�|�
%�9�� �
��^�ӁL��d�T��LC��Z~���w ��MU�{hY���`�m�h �sP���3�7ʹ�TN��,�M��L#G���1�Fۛ�S�[�A	��c�j/Q�}N�(���O�8l����%�(6����˙���޶c�����-p�˹���>�?��A����\)F:#9��L\������N>xKŜR�RT�C48�9�*�b*����ѕ#V9BB�"֟�I�|͉�E���1 m��}��c����d)>|�V�ÀF�� �%�I�MZ�N5i9�
B��@�Iy����cD���XY�"�򞗱
X,��p*�C��clW���Y���i#��p��ن=���¿r�IB�Xtb�_l���0G�GI�|R>���x�r�C�ec�a�l[��+y��Ś�����hkfɾ t�S���A�i�c,^�r���Lؾ)�����ϧ5gܐ\Ǳ�'���O�F�\�*$�a��}�cL�$]�?Y>�ܰ��돑"��d\�Ф�����1�%���r��cL���c�tX�W�#�}�� [������5��!��;%��~	n�b0��U�#�o4��`N�A��a�{p<��A��h����s�5��
��8*�j�Ό��8�q,ǳ��D�msx,�4͐�\�_� #[��/�<�a����y��3T�D�Z�{Ȅ�aŲ<�v��9����"�bt�;���I;��ۻѨ�o��r'����w�H���Ô�s��f��鳌3޷c�|�_¸9~k_��d�bߋ$��a��c��I��Ź��,x�o�����"k�K���+��+L��� ��|��!�Bða���?)� �Z��o�n��@P�mE?C�7j�
�|��t�m��	�֔���P����� ��I#׾+���˜gF�E��x=��\ɐ���Ƚ"נ�3�G�L|��Ey��Cƞ�7l+�����6��ʽr�j�˳JGT�Xܞ�������yG���r���;;�I��b�.�Hby�4�Z�y�֐��ٖa��O���1G�l����s<��}��O>�$B�)�g��@v8�t��$��z��wC���,�X&Y��YI�뻺4���A#�xH4�^����G};� ��+��{�0��oCO���~�f$��m���Oꮄc�؆@V����Jt���� 9�H� �:�8w~_:N湜�t��p��]��xN<W�A;�?>b�T�n��Dú,V�0$x���b��ʸ}��_�E�#,�k�x�cH�׼f�U.�;�^��uD�����y{��@.kWT��\�u�&U�8�R��h�`ɲ�<阇����A2���'��o���9�c�6��$��4v�����돮��{��V�$m�c������߲����>S���q�o����\�u�&�c���y]�>&�r�{5���En�)c;��5�A��$��t8N���Ϩ:�l�w���~��q�V���I4lݍ&J;�Rg�Ą�O}J��k��R���z=⹂u���,���}랭�{���1�]8��5H��~y��{-��!���KLi+'���Cx���3:�����',F��m�!������F����g�ugdL1K���?B��*�qW�ټ��Wa��ф�f`7���ѷ4���'��������5�E
�I[w'A�?������Y�7繜���~��NC�y��Wߍ��I�1)�7�`a�c�~|��A�A8�6(�	F���@����"�Ni̚c����@�a�L;M�
�%���-��0%�n�=��U��3�.�*m�m1��;w���U�6��~���-��@����v^sy����'�_n��jݏ� �SH���=���ݶ~�����-/�@��,-Q�g��s���U�8�Y���{�Ԓ�w�lvj}<�w���X��)���&�!�kz_�\>��Ǜ���M��iD�mt:$/2��A�j��A*z?"��kM�p@��c}���2�{귳�,3Թ1�'����p���6���hp�������?�/�Ӄ�O��x��u;�O��tS�G�)�9;���508�eVi��Y1� �NsY�Xq�?���tF�?�˳����od���X�,縑1�7�y�ǀ:���%ݙ��G����2q���q���������^Z8޷�w�o*�l���k&������Q�57��ϫ����G�[���E��0�Nz�w<�W�.X�L[<��]��]���p�'�}�,X&,���<���e���)H��}$��q�g鱃t��,;��_-���Tӟ̸�w�]?��|-���q2�s�ua��׼��(���w�)���us����I�>��I#ٻ�d���s��8��^�~>A�7%����I�β�Pb����O	�ۯ�]���|�vĲ�{A��.~M��t@����"�e�;-n���f�o�|$O�>���a�)t�NÉgM��1�4���4�f��K��<���i�Z�-#�h	��RZF��VZA�����VQ��O��BZ���N���ѧ�*�{�>*��K����ʩ����H���}�����j���oRm��� m���=L����#�)�P#T���&�N;��v�.j���c8��
����N�qz��!:LO�St���g���.ꦣ�C��8��	�~
� ����Iz���/��):M���"}�^�?����K���
}����B_��џ���U�3���s:CAߤoѷ�/��;��5}��g�-�C��cu����
�˰2�ӑ���Pu�^����Ia���p}_��^P���*��2��AU��vX��R;˿��Z����wQ׃��x�Q�7A[�tY���^�<�*/��Y���êo��'���w�}Y��_�ߢ=_�����Wl:�0)���?K���5��}���j���r:�@��@�ݳV�r��ە��v�7�C�{�)<�hjyC���$�_�r�����7����-�1���y����ɿG�O�8�I�+	/�+�#�cj%}���n��߻C��O�_<���?$x�눾��-����?��7��ȇ��O�yQ?��rn.,�.}]y�
 ������ʀ�@ �wmZ�V`? �]Oǁ�%�U����u^��n��\���3 ���% ]����w�*��� 8����b�q�-ܫ|�`�,����y��ݸ� d��"�% �sC~n�ύ]��7��
@n���n�Rly�[ ��y #��
��s@3 Yx: ���,��<Е�r�@� ~&����`�)�S��#�m�`���H�M��q<���c��$�(	�0�"i���� ]����O�67�	���vզ�����#w�X�gV����j^m��D�Ժ�@�������ؗb7ȡ��o���O��[|%n��E��kp�8{[�O���	R �Z��j�� fN�A������A=N��	����o!���b S
�g�Ko�B���d,��t�drxORf�Ác�����J?��d
&��<nZ��fFI���3[�~Y-�#�x��&���ѓwL��S�#�CԗH# Q�%~`��q�����;/�j�S"�\�s�l�2}.�����)��҆��w�����g�uH�!>`��_c��#�p=�[��wf�C?���{,u�Н:����'�0���y��t�o��"�!	���]4�=�Z3�y���ѵ~�P`7H_��hπ�������O�{�j>��02�|�}�|0t����]�Y
�M~�&Ț2EdS�SF6e��5���B!�u[6\s� �ZkIQ�[=ε��k��n�p�]7���D��Q�5[:�,L��DDf`21��΃TU��V���u����t(ˤ�R
��K�kЍ(+���,�>Q�>�����X�d�+�r�
��:Oy@7�*�e�V�uZ�`kem��3�{���3A.ѡ�fz���æ���Ȃ��h��^bo��u5���%�|�2�EŦֶ"%�}�dy�&2I�Sm��^�@s���7YFAF5#OzT b�[n�d5~`��c5��P�����!a��6�U=e6�ǭ���5ƭ�0v
@=�����?��x�^�]Q��պaV+l�Z��Y��MG7�z���^~k��_�n���Q�k^�e��^��Ux�jw<�w���W�yw<�7�Gg>������ ���L� �_Q)4I                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     �      �[p\�y���-c[�-ٖ�k��Z���@�6�ZV"KB����H��+iþ���ƺ��ʒ,JIH�P��4%-M!���)e�&�i��Lөi ��Sܖ���{��{�Zɫ�4��s����yݳwm]�Xـb��>��> �t9�D��}7E���V�øq��R0>sQ��/���t�ڗw�J���DI�R$���Ņ��]\��˅z���@s�sa8FR��*L2��Ir|�k^^����p�J�_��x�������پ̅gn�]E����Da�*܁&;L�{��)`��nFa��(<)k���}Mk[��'��h��@}Ñ�F�/��Z�y������Z �
Sk����Z���v���m�hl��þyjk�[ێ4xE-5��6����K�M��m���mmj8�V���~�zs�Z�=5��u�L��-�:o���j�{Z����[W����[���>�7��m�i�e�]T�in�o�M�Ua���k����"T��|��h���z���6�G]��V���׻]F`\����N��#�h<���Z�v�'r�0�i	-~�+�H�bI{w�j����/��Mca-����Fr�Ʀ��es0��q_@����]��`$��i��5p{�\�H��h���D�3}񠖸��k�5���־����C�Jͭ�0DW�p�x<m�z�Uj͚C2�憑R��J!Ot�ʖJ�-*+�tW����+�)��%{��'�=�2�j���Rӂ��UYǵ���˘8V�N*���S�c��?ԯ����gGƏ����IO��8��q�p������2��?=�����C�C����7<��tz\?�?s���t���PZ�q�=��q9{Z�`������	�qfl�|9cX5:Ɨs�H�24m0Rޞ�$�cP�2n����fq����pu��(1���Ӄ����1ܦ���ّY��a�����e^�@��Ѵ��'΃�4�$�q>��R�	�>�d|�92Ĭ��?30.K�*�iNٹ�pu���"1�b�Ǝ�fO�n��ȂH�l 	{��q>).�>[#�;08|
Y��T$B^&y}F	6"���s/�|���O>&8���c��ˤ�74��Y��ˤ���YJ�ˤ.l���?�u�.��nttV��s�˄��KI��6/c�i#��C"�F�d�H+�s/c�V#��~Ag���}�}ø�f�)9�yůB�)^wy]�Ա	h�۞�f�- ��� f;�s;d��'r�<L�W0as������ �ܴp��	 �7�G�uK� ls���-�����Y
=K��z���z���z�a��,��e��vC�Ͱ��$ �n�!�r̋���rDa9��O�g9d��  �X+^>�~�`��;���QŰ���M��?&*	l(��%�/A}	v,%���,��R�R
_K��*�]�VA�*�`�WA�j�5r��W��ը_��2ľ�)C[����2�AWd���2�*]9�S�\���r�]��r����5���nb�1X�]�Z���ka�:l�֡}���~U��i �Z�|��m���ش�� [7�~#��?7� �I�	y��7!��`�f��y�!3�o��[�G� n[@�u[����}a+��V��.ԹP�B�u.�ۆ�m�ۆ�m�����q;�Î��{;��?w n;��w �;���X������b@��>��<��@���K�~Ŕ�>x�^7qQ��L�ʁ�O$��2���:��xBҝ�|�*d(
��°W!��QG�Z���Aˀ��9�8��B���U�7�����0P�xNLώ�	�'�66�2.��N�OѺ%����-��X ���_*c�Fb�����IX�=.��+�n����E��墹1�<vI\\ ��>))4���:���;|�6/�جr�	\�8�E�BƑe[d0.�بxKp���OB���{Z�Rq��:Vd������$�������e��m�,�O�>�������i��A��X���>K[.[؆=Y����O�)?s��6��զ�q�ɺ��_*ۯI�*�˖����1��W}H�#��˥p��*�p?f�n�x�aU�Ā�KX�����3��&��K{7+a�2`=*�nй����+"�~��,𣮏ˠﰀۘ��%�t�W�9ˈw��K�ԓ�ב��/�\��t�f�|$���̺I�����B��q�C@ٸW�33�ۇ����L?�C�BP�|�y݊˒��fy�����O{�2��E�V-rt�F��U	����؝�X3 u�ނ3�1�pxh �:��i"�f@�K��=e�r�=��=5��e���ĺ=<O9 ۔��ވ��}�c?�!1���b�������T��3B�3_$�K�X�9G/�-$t��b����9���n�
�����T-�hŠ[,Յ���~{�b���~<?=�xK`󳘗v�'�b��%3��1_�^o%�kǙ]W�~�gZ���ù�@�z2s���7%�����El�z��7�7���MO�8����������C쬵({�V$���e>�Hy�r��+����n]�:$-�7,-�Z�I�}9��$���~���I��l0=n2��\�Q���_�m�� ��O��W��~�&sͿB�Ǿ��>�J��ͱ�&1w�:��]�ޒu�qa�Q 1Ol~��ݫd��e�ʯ�S��|��4�����u�����C���s����ږ��.(��%��+�⃗E�~q�8�<_��g���yd������B}�۳���{2����1�L^�1c�*K���I���<~1x�ݫ�8�=瑟Iy���2q�W��;U"'����\L�]����G�*��.�.Y�[t):�sB��ǀ�'?'����U�R?���YmVp<��g��
ɯ�i��l�?�9$W���߫�g�'���b�95�3����_xO�&�gw���d�'p�Tg$V�N[���������.r�!����'�����s�U��bk���n}�W�}� ���6p��X��UL���/K�@��1��u�D##D�E&���T�3��&e\b�������*gL����K֫��f�:����^*t3�Î���7gۢxَbYq�uC�z���|�$���WXdYt��ƹ�޼sR7��:$8O<o��\_��$�����Ҿj�{��0-i.[�wY֑��묹T���j��-�1jH��k!�
�ύ�����b�\]����F���Ov�ݥ�gϚi��3"�x��cv�<��Ǜ1�o�@g\�+P_Z:{�/%��E�}J���xW�]�r6���o߈�ô��X���@���47b���$�_����787�&���8�7�q�mب��1_-��)���E�7����.�l�!}/�̫����s��*^�R�b�X*�<{�Kʘ���3�W�Y�ʸ|��|���Լp|�6˪��>{<r���9{ɞ�
�a�3F�edǣoІ�d�TU�M�I�g'>��[�5�����<%*�;'O��!e��y*D�������ϟ�c���Q2���Q��8��|p���D�U�y�9͝��9�ɞ���a�U�-_��,?���"up��/�^�I�{�%a��l����O�w��q�Ov>�9�RϞ����G><�E�g�R!u.f�d�iZ�����E���i��Bs@��c�'��+{��\k��/�3_��O><���B���W�RϯT�/���o���ę׫��;H�S�C�9#ˎe><�{�|x�,��A��ԅ��uP����Z�.��.�J+]��?t;B��c�<^��fZ�+���W�jl��ip�����K�&�L[�T�hm�t�
}�n����1�U�I�t;݁γ��E���p�n��t݋��	L �S5�?�G�Z�⡾�H=}�>�r�����~���� =H�0���Я�C��Yj�1��;��҉$HC��
����(��F1-Ez��RzK[/=B'��G1��H�~:C4HC4Lgi��4J�h��i���$=F���8�&=A�����Ez��D�M�C_���w�+�Uz�~������������!}�����o�ӟ����m�3z�^��П������]뻕v~5�0� X�m�8< ����v@��w����Z��X+�2l/C����$��.n�)�ߗ���6G�ٖ�{J��f��y�_�Y+?�Q�u@�a����ڮ��9�I�11l�"�����Ӿ��,Y��i���r3��:曔u;%�������=���&؞Ll�`��)K2}Ab>~�h�i�I��mk��@3�`��zǘ�O~����$��y����_��Wo��I'I|m�����:	�
�5�9Ǥ�����$��=������?�S6�T�� ��ȣ��*Vbqlتذ4�&��mpǆi߶Z�����Io\ |��`������gl�mX�m=�� l#lX�l�׆%ǖ�Lٰ]�=`��a{b��#�A`F�1`B�S� �=Ab�A|�A}K��Z� �l/l�	��mC<l���!~'eG~�w�H���;�c��v�h�mv<����R�������e���=��������Wb�Xl���1�.�9/��;��C���r�w�8 ?��@���� yw@�[(�:�x��v����D����� �vB��L�6 ����D~�ȅ�wB�s\�Î��n�7��������� ���|@t�-�u�R���Ǉ�+��k����|a:��&�@g�"�p�O�#��B��iq�I�/�R�	�D0��(�k��֕%�T�K$�x0�0�B���ᰏzzc=Z���J�|�zD�G)�(y<Jɞ���6��SW�F��	Jh���B#A���h��(��D���)_���ja����h�/Y�&�3��?�%�:Q��Z�?���T�R� ���5X��݅lX�&5�ŝES2
h�������t� *���{��G�",+���`�Z9�l��Q4�B ��v�����
�C����D�*mq�;Ȫ� �}�8Ժ9_�a�@���D�Ho\�2s���S�E|R�Gv�������㾐�ya��
ͲO���9�(��B]B��Ld:�(�H�G����
i'�#B��D��Xz�T�L�
f�`�Z���zAS/h�-4�o����&A�$ț,�M� ��h�B��$��A�zP������m=�x���xc�3� �쟢�g��	����ƛ
�&�5��Y��WP�M�B��hCD��
� �Zȣ� �r�BJ0�c��p�Ƥ��L5-����{��<                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                �      �\t��y~%�!�r�,��`�����ۀ[�P۹Х�p���K�!�2�_H dIZ�nY�u[�u�-J�I�s���zvvκ3�$=M;38��8h��]���e@F����������޾�oa{l{(��l@p�Aԏo���,�"��{����d��?���7>u��%�J�}6����9hKJd�Z��Ͳ��|R�d��h���
��k��\�Ts�+�#�9h��w�R�ú0��'�S\sx�k��΅�?�G7��7�?>E�6x������[701\alDa9��J�P�h:
}\8��q.x��/o�ruy�6*���h#m,���j[}u�}T״�����ܴ�N���Ҽ�j�J�먆j+��,��,U���jh�����ںmU���V>TQU_[��
ں���Nk*j�T�_W����!��6��ZZVY���R�5��*�ET�����Tl�������[����&TT�m)g�b*+�Z�YhM���Ҳ
�U>aIٖ��j�㲖�޶���w��l_�+^�s_���W|�{�;w��*wooi��5t4�X�+mn��0S�������)�� �ϒ��ʛv6u44�*Z�l
�j��R)��ewjaT����L����k�u�5�h�������1_U�����͍�.��kؽcUK��	Bڟ|��iGSC[Sc�J�/�(����[�������!�Px�������zX��A�����&8��Q��S�)���PfDa�w��
��$����P���X�%�K�����S���,��]5Gwu�?��/���.8G<��G���1��a�{�Fwo���}$2�ǈ6�G#ǻ���4|����	�䐼=6�/|l b�{z�������a��A��8��1��L�C�q�	GXhd��3�t�9N<?|�>�!������0���l����B��� s�<����j�)�� .L'��S/�6��L2�����@Q:xtpx��<�÷�0�g�9QBE�p�plu�p =a�߆�;!8� Y�)�Hf�I4a%u)�t��P��^H��٧C�����sl�c %A�}���ADp�M:��x/�8z������2�"��ی���OA�c����Kw�/ԍ��C������$	y�w�§G�8nO�.'����d�{�Ƹ�	����*d,
�Nu9��<���p�Əs�"2���/C���^\D��ː
m��2�D�(M�%�`�[�Y/C�a�H=(�$Ɗ���� �!��r*�� �moa� C��c$�@>�I�0�;F�
]�Ѭ$��%´* |�~��(@;N��'�\X��P�z	�aU�x����;�N����i:�M�����n|8��� �v�m7ڞ��g�vhg�6�9��m�%��~ zx���=� cX���\ؓ��\ȼi	����fȼ2o�̙�}&������o��,�dhfA�,ȝ��[Pw�n�-��l�ͳ!s6���� ����9���}�΃������o.ښ�B�\��s�y��<�1k�y��<�͇����|�w>ڛ� ���.��|�}+xo� �{�({�W�C��އv}�Y ����y[�6o���!�v�����Y����B��su l[�-z�!_æŠ[��-A̖��%�m	d,�R�/�ߖ�~b��ː+ː+���r�c9|�~^]V@���f!d��B�[�D�V�x�
������C�U�K}端�% ��S���Aى& ��L��pܫ���ǁ	��c�i"�6 O���
� I�ճ�{���a������"ǋ��:x��:�h�ǀ1��N���c^6��B9[I��O�`tu��)�����X���1Q���vb�\���q�|�bpyJ�(��P��B�xL��Є,�yJ�!�K�Y��t�7���p�k�1��$����5�3�#��q;:ߴ=��Y`�Z�dY��~e�Z��Yd�(���֡�b�5*q!��9��/G�P:�	�ݸ���׷���C�.e��3F�K<*e�.q����E%?����I�
�m��Ԑ}ͦ�t)p���V��5�>�H�P����5}��=��c�]J?� �ݰ���{�o9O��h�!u�,>�?Qw &ۋaô�}j�+#��x����X�5�{q���qiMT��\���z�'3�&˯V`]T��5��Q��|��~�'�y:���=�q�J?�.1� ��)����?�>����<�)���وj�}�|hHl���}�q�}\�N]���3��Q�B�>�+�P<�Z?̥o���7�F࣋_҅�Q
]4D�q�q���1�;�OE�!�	ς�@6��X�y!�1 $�"���@�LxQ���>�����h/��3:���v�Ξz�g�-L�����r�x<� G=�W�J����C�	d)��ʖ��ή��2㗧 ��#N���~60:��p!VqV��l�_�?������/��co:�}E�ф<L"n��"�G��=����T>��� ���mB�L�&_��+�w�6Jt��W�VMf�h��a���>\�XpN����(4
}�0X����n���[�V����w &l�y�A�3j�k�|�#���F<����<ɗ|�?��$�S��Ub��#J��|9��������uB7��#�o=u�c@q�pZ�G1�%�>��s��7���!��� �2�b��vQ}�$��e�/�x�wYƌk����Q�V}����,Y�{��<	vu��̱���X�q,�^'�E^����@y�"Ϛ!�,~�\灳1���
� ��Ba=����n}�sZ��:�8F�\��9q�C\���1$M|0�����<l#��:��J^��K�Q�_ycD�j�sI��x��9o����2�F��sl������Z�K�\� �kw^������z��~�vc9~������{����c�U��Fz������:�׫��2��vì�1��������y����P,5����N��k'��s4~�(��\�3�u/���usbHz��Ml������d�V<�α�O��zػ'j��Ѯ�TmǕهoD�>���%��ۣ���I|m�'#�y�'��+ْc��x��?Qx��/�}�sT���)Rc;�ǐ�slC��t4=[&��"6�{�+J����]�\��E�m1����[��W�~δ��C��Ϙ�s:�&�՜���[�)ی�>$�1����䜚���9Or�y�̱�Kճ]}
o*�Y��;����@��J�.\�����������YY�v��R?���?����<�0*�h���v�}J�_"+W��w�6Y&��磾h�.A����+}Wч���-��Ǐ��=���ę�!��]0m�?�K��8���ɡ�̵���3����*tEJ��#V�f� ����f���$�)0���P�p�1�������#�1�!s��"�oP�@�y�#�c�9�ۇ��wcr�mFq����[��NPA�C�3�a����"���ǽm�D�@�}I�Y���:��*�?����������T�����$s���K�?��}��x>P�g�wx]����"$R�E���߼ɠ7m����%�3�_���.��ޯ컬��O��l��T��2��3�gl`p"x��H�}�y��Y�B�l�,s��M�}L�ɺf<���I�v^N�g~����M��K,�'��U�ܪN�q~2�?p.�3�7�ƿ�����p����.O��
��׈�`����ڦNU7BW[��I�F����+��N2��F�|��8W4Eؐ�@��<4T����{��#����Gl��r��*26�46�}e�~Ё��<NL�n�ـ_��"�w��1'�'s?=F�G+:��C'�pC7�ȃ�N�O�Vw���{�|2����EC�i��-�c'����?g�b�Ug��9�B��A��L��Tp�';�9��c�����p(gD6
u!kƐ=g����D� � 9��v�ɍ�l /`�;�8)ȡ��匜{���r��c��^��UO��8������8���ݕ!߻S��w�������r���W�[�eP�>�y�tCF�>�{�������%����/����nS:o�I:o��}ʅ��J_��Jgߚ�陏�EBŤL��Ȅ�T�&�&������;úFёb!�������2��\'�;B��a]K~�>c��H����E��o�.�ӯߚ�\�Z/�{��N��{�|y�=a��)�,��Sf2!ב'�I�)K��{?.�9A�I����L�����΂�{7>o7�p��N��Fϵ���rS�2��y���e���K6^��7vS�ڱ�̽@�r�������O�W���\�Ѓ�C�)�y�ؙ�;}��qs*�q^�ʇt�U�ʇte�ZO�+#9���s]���>���S�����)�`^}>DS���u��|��u����6~�v�wL�c��D��n�#���O�/�M��e����s���3ک�H5^�+#�x��>_aL�?���?��L�єHx��^��{1��>R��l0�R�/�w&.2��0o�2�}��ߥ+C���T�S�s3��%U�k��t�Z5���.��L���Ƶ��u}�Fv�3���1&�h:݈D���<�K7��4�f�-4��_�ͣ�H�[љ�G�6O�s���ZJ�h9��BZI�0���w�]�yZ��}-�M�0Q݃	~���2*�
t�M��*��E�������V������~z���h}������#T}����@�bp�A��:w���D_�'��v�nj��[��`=IOaA�I{i=M]����gP��� ��>��t��R��� ��qz���t���S��!�H/���5�:��?�o�7��O��S���JNߦ��������;���7�]�[�;�}�~@?���{�z��'�p�e�}��_|_�p|���`~&�z��&���m�\J��m}�/�o]�.�c�z�t�����N�/����:(��w�	�.I^��{\��Qe��(��	��%�n�~~~��+#��g��L���Q���o-�nK���
�m{�E6�A��Ƅ�/~{q<�}$�O땈K2��>J�3)0;	�&���K�'�O�o�x�����o
�;I.�y�PC��N5�>I�B7p����H�@�% y��)7�|E_$�A�7H�����d����_�i���9�[5��NM��)�;bv�6�6䐍�t��[. l��0u����R6 �l,ym�M@-���Æ��q�@3����6�x
�Rٶ���<����"{I��q�۰co����� �c;I�d���^��b�c���� �	�����;�p� �/��,X�_;�c��v�h�nvl3숍��O�������h��K ���|�R�ߜ, Ўc�%��n���S�������r�v�1 v:О�w�>��݁v�h��;�v�a(��e�\$U�A�Mܬ��4�,K�Z~v�9T� '��iR��PO&�]��hj��8C�*��D����@[A[�AA[!+���mm�u�����B>
Y(x�������p�*h���o(|��(��~���~�����~��Y�ͨ��5k��O���K�ܟ�2�8&;x�s���Lz�(i�8Y?8�YG���YF�H��Ѧ;�]Id�4i/�Ⱦ�fCO��4����gʏ��?��D:��d�(�8�,�-�&��1=Y9N���hGCdYtǩ�*�t~�C�)js�y��	Ciu����Xkl4e��{�bBdt���K��*F��Q����,�><zZR�N;DA�D�o.t�c���׵�Ō�rDf5���b����C���d�.�h�C��y�U�{���uAj^5a����a*K�Q�l��)�i*��h�4��1�;X�4�C_׳�Xho���{��ں���7��vg�\'S;�Q��I�wv�D�X�5w�X��v����N�;!�6�]c���~��7�.��I�?���V@cM�[��.t�cx�Q����8��������{����|�e��j��m	�ؠq�]m`!��yC�Ʋ�����m�^�����V@c����	1���l��1.r1/&\�4=��+��{B��|�]�H                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         �      �Z{t\�y���ږl=�oI&�4�	AT�USG+km	l�Hr�)��^]IV�b�*��굒��R�%$%4�)Ii������$msz�S�Q�q�C[��$�Ʊ���|�;Z����͝;�����ff}���PY@0����{/����D�F=�I��D{��˻_���I��@��N"G�c�w�W5��7�:����	�̕�U\� ��+-�]\���J��)ֈDT���Gu�	]y��_ ��-��n�{�_��C�M��ڼ&X�21l��re=*m��|L�|�+��|�+�g������8<�<����y�hǑ�T��m���Cm�g
:�GzC͉H�@����v��Cvo$=H]���I]��m-ݭ��=�E)��r������j��m��j�7H�;�ڻU�3��q�Hw[G��{̗c�u8���� ��p�3p xܕA�Z��W���c��[o�u��u���]����NV��ŇF\;�#�v4~�����xt�N��}�m7py데~_д�^���xkP�	�Uv$5�g���o:�v�Ұ��1���D�]�V�t��H�El�y��*/��ۗ~��ҥ�/�J������#Zp�sY��s��'fQ��q��Yg|:;7�̡��΢�dfG�&&f3����}t3�Xfbm�����9��4zg���6�6�k���v��3�(�vk,���5q�k�s�y\��J�m0�q&�f3Jq���n1�́$��\ܚ��ř3Ҧ:\�l�k������>=����=AӬ8�1�\mjj3��.�%�`F��9㎘f�\..1�19����d��pY9�ܜ���]��tl<�b�e��|X��It Б=��r�іg����SS����QP��Y�.����������Q�P�:3�����hfr��?�^��9�g����1�w�gT8�l�SXLLJ1>���J��j^)��������
��-V�����A��SXLLH1>������Y�V�0�A���L֝z��۳dY_\'��}��U`{ 6k�
�� ��W�o�Q;��=��&�y@��<�O� �}�>�$#l�>��R�� ���$Z�k� ����/g�����@��~-tY����F�n��:�r�Aκ�� �2� �2ʾGT���S~�1��W��?�/�?����� h�;�s t؀�7 ���}з|7@�
����@�+ ��U�����}��W	*a_%��*𮂾Uз
��^�XTa\|V����T�?��m5xUÿՠ�~��jȪ~��N.~���?~�ȏ�#?b�G�6�o#�7b�F�s#dm����� �M�m3|���_mF,7�O�1~b�:l�-���c+dn���w[�w+�n�m�t��۠�6���^���n |�C����7�j������5�a�ՠ��j�Z�բ�}��E_-���W��`Gt�ü��~u��u���+�o���@�m�wԂp�<s�+@�q�i�@���iG=y�]�'� 8�=��I�9��r�(�T��Z�f�,����$P����	8���+��k]	��h���q�e�m�]�.���`%�����b0y֋]������}A`�(m��|M��J~񥩃�	��ǋ�Eh/c�ύ#��PY�
������Nt�B듶y��`q�s�������UB���(6k�	�ם?|h^ڗ���������G�X��<��)c_��y��7�mX���S���b���mX��)�O���kI�}Qt��6�d��$cL�uR�>�ی@��� ɓ�q#ӏ�;�G�5=���|�<8��69��x}~0����fǝ���h�:�\E�ZX�M��q�9�O�7-���\y<��Ӱ<�-BsQ��m��8��E�ˠ�������R}N/�#�,�XL���_"�1��#�a�r��A�7��+A�f��"{@7ǀ;-��[G��R������d?�F*�a�Kg)��4���set���Q}^�ւTț}5,>j���%O�m�Cj]���x��.6���-�m=�^�o$u�Y/�y�G� ��N���<j���Q?>�F�P~��"m�p��}��tE;.����̯Md�Zy�-��o���p��1��{��J��L,R~oe\-�������g·�i�>�;����2�sf��Ӷ6I�Z����6s����!��?��C����J�w��_���k�O��|�}���el�Oh�pN���9���o��x�c:����I�O�i=�<(:�[��Ya�Z3&���gW�q�3����Q񸛲��V�!�os>1ci��9���!�nƻX�D^�}�W� ^'�8�Z�<���px�F��w�v9*/���"�7On����Z�y���/z];�s�ޣ���io����Z>W��4��s�H���y�*���?���<���=BS�����|�5{/-�a}��}��y�n#��y.�O�׋黒=<�u^���qy�kD��l��?h�!�oRm�w�����s�����=y^G���e`Q��ϓ�O���u����b�5��E��/�2���s[#�s��z�|�d�}�</x=mY���-�Y3O輡�� ��: ������a�Cx�9�ع�ΰ|//��`������-��>N��T~���zMb�֝�x�Еz�Z%��U�_�J�M�����g�R�x�h�ej?�Ą-�_����ρ���v��.�!ѿ�;��Uҏ���u��B�H�\/�X|�o=���2�kq5�w��������y\�L��R�g�����L�*�y_l�q�=�Y��:jb?O��������?�z�[-��U�oZ%�֧Ի�"��,s_��5L�u�{�>�����gw�Z/:G�t�*�f�WD�ZMc�t���pJY�����1~O:+��}��rV�^�f���h�f�.�7W�ѹ��.�W����+��=���i�/w�#Z��W
�诈���n}Ѩs�o�?���G�'ׯv�t/����%�\]M.Qi��*��M�h�Q�9?�~r��K��J�!/�Z��Y��zڀd[	A���w3�ي��v(SKu������0����#���;q�y?]O�!��n�_G��E7��8h�J��o ��c܁E�A�CpB Nه���`r�ѝt�!j��0��ԅ�|�>LGq�:�K�o�}��p��_�v��l2'�^�qE���#B��)J������(AI\��t�N!�Ѓ�0���"��F��� -M��=�t��Y��y:�)�1���c���տO���p��=AO�S��G�4}�����g��Y�=G�k����g��sz���+�_Ћ���e�
������z��
��ߘ�!x��a�(e�X���g �f���=�R}.mP==d���q�m����? �u{��>���`�{Ί�,�Y�c�{�v���'�� �������1��7�����yx숲�uv�,WUϽ �,=�x�p|�>��2�f���y;�~I��c�6XHG�kF�pM��P�zv]�;*>=*���'�q���e��+��1�|�啶AW����^���/���w�����X�q0����+�C!X���n�U1��ߗ��f�Ŧ�p�`��mġb��ob��lg��8��Z+)qs��z;�$�3r���4��Ax��M'��?=	<`Nb]�oG�L�z_�E��Q�)w+�/R?����O(?%u��_��W�da[8�Yk�;!���[0�Bʷ6ɷC� lV�m��ڰ��famY8�Y�Z� �Ml?V/��X�G�(`��ye��� �Vփ�m����򇅣�5�ր�_����Uk�?y��#����/���
�w�? �
�'�X����z%P+1�	�Z���@|<���:z���4��x ��>����H}'�� �x���=�o^��z��~!�{���^�ʋ-�{H�I/��\K��^���v� vz!ϋ�{a��� ��\/րr���	�>�/们 d�+�u���. �}���Qʇ9�ld�b��}��ld��  �� yɇ��ñ����`��~ ��~F����B�h*<��5
�d���Az Oٽ'�K���H�z��(��D؎�(4�Z2�U��H�?j�P(aǢv_J��W��d�ND���P4��p|p0D#Cv��E⽔�������S<fS�T�R	[m<����I���aJ�'1�v��" ǣ��#���I�H��ԟ�C��d*��P�]"N$B���k�	T��Ҫ�G"�H"��t�n	�64A�wsl`�HL�7CR*���ī7~*FnT��Q������x�D"~�c^I;�:�7b'3��|�M�Do���?�F���2;C�X<�Ö��#,���P8��~�G<f�0�vÛP�̽���M�i�"!8ih@�[��۽�⹐�a~:�D?Q=�1Op�QE��HiL�&�먀
L@�P����P��H�/AڧU
��A58h�F�)�6E�fд�h��jW�:y�"�0�;� 7j�52�5���G��#��#�1�Tg�@<�~;1�5{"����O�2Ɔ��P�E�uC�M��V�m5�6۹QEQ4�&���ᆘW�qE7��B��9�儴�V���tnĈ�L�N�5��I�����	Pg�3                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             /*
Adept MobileRobots Robotics Interface for Applications (ARIA)
Copyright (C) 2004-2005 ActivMedia Robotics LLC
Copyright (C) 2006-2010 MobileRobots Inc.
Copyright (C) 2011-2014 Adept Technology

     This program is free software; you can redistribute it and/or modify
     it under the terms of the GNU General Public License as published by
     the Free Software Foundation; either version 2 of the License, or
     (at your option) any later version.

     This program is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     GNU General Public License for more details.

     You should have received a copy of the GNU General Public License
     along with this program; if not, write to the Free Software
     Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

If you wish to redistribute ARIA under different terms, contact 
Adept MobileRobots for information about a commercial version of ARIA at 
robots@mobilerobots.com or 
Adept MobileRobots, 10 Columbia Drive, Amherst, NH 03031; +1-603-881-7960
*/
#ifndef ARROBOTTYPES_H
#define ARROBOTTYPES_H


#include "ariaUtil.h"
#include "ArRobotParams.h"

/** @cond INCLUDE_INTERNAL_ROBOT_PARAM_CLASSES */

class ArRobotGeneric : public ArRobotParams
{
public:
  AREXPORT ArRobotGeneric(const char *dir="");
  AREXPORT virtual ~ArRobotGeneric() {}
};

class ArRobotAmigo : public ArRobotParams
{
public:

  AREXPORT ArRobotAmigo(const char *dir="");
  AREXPORT virtual ~ArRobotAmigo() {}
};

class ArRobotAmigoSh : public ArRobotParams
{
public:

  AREXPORT ArRobotAmigoSh(const char *dir="");
  AREXPORT virtual ~ArRobotAmigoSh() {}
};

class ArRobotP2AT : public ArRobotParams
{
public:
  AREXPORT ArRobotP2AT(const char *dir="");
  AREXPORT virtual ~ArRobotP2AT() {}
};

class ArRobotP2AT8 : public ArRobotParams
{
public:
  AREXPORT ArRobotP2AT8(const char *dir="");
  AREXPORT virtual ~ArRobotP2AT8() {}
};

class ArRobotP2AT8Plus : public ArRobotParams
{
public:
  AREXPORT ArRobotP2AT8Plus(const char *dir="");
  AREXPORT virtual ~ArRobotP2AT8Plus() {}
};

class ArRobotP2IT : public ArRobotParams
{
public:
  AREXPORT ArRobotP2IT(const char *dir="");
  AREXPORT virtual ~ArRobotP2IT() {}
};

class ArRobotP2DX : public ArRobotParams
{
public:
  AREXPORT ArRobotP2DX(const char *dir="");
  AREXPORT virtual ~ArRobotP2DX() {}
};

class ArRobotP2DXe : public ArRobotParams
{
public:
  AREXPORT ArRobotP2DXe(const char *dir="");
  AREXPORT virtual ~ArRobotP2DXe() {}
};

class ArRobotP2DF : public ArRobotParams
{
public:
  AREXPORT ArRobotP2DF(const char *dir="");
  AREXPORT virtual ~ArRobotP2DF() {}
};

class ArRobotP2D8 : public ArRobotParams
{
public:
  AREXPORT ArRobotP2D8(const char *dir="");
  AREXPORT virtual ~ArRobotP2D8() {}
};

class ArRobotP2D8Plus : public ArRobotParams
{
public:
  AREXPORT ArRobotP2D8Plus(const char *dir="");
  AREXPORT virtual ~ArRobotP2D8Plus() {}
};

class ArRobotP2CE : public ArRobotParams
{
public:
  AREXPORT ArRobotP2CE(const char *dir="");
  AREXPORT virtual ~ArRobotP2CE() {}
};

class ArRobotP2PP : public ArRobotParams
{
public:
  AREXPORT ArRobotP2PP(const char *dir="");
  AREXPORT virtual ~ArRobotP2PP() {}
};

class ArRobotP2PB : public ArRobotParams
{
public:
  AREXPORT ArRobotP2PB(const char *dir="");
  AREXPORT virtual ~ArRobotP2PB() {}
};


class ArRobotP3AT : public ArRobotParams
{
public:
  AREXPORT ArRobotP3AT(const char *dir="");
  AREXPORT virtual ~ArRobotP3AT() {}
};


class ArRobotP3DX : public ArRobotParams
{
public:
  AREXPORT ArRobotP3DX(const char *dir="");
  AREXPORT virtual ~ArRobotP3DX() {}
};

class ArRobotPerfPB : public ArRobotParams
{
public:
  AREXPORT ArRobotPerfPB(const char *dir="");
  AREXPORT virtual ~ArRobotPerfPB() {}
};

class ArRobotPerfPBPlus : public ArRobotParams
{
public:
  AREXPORT ArRobotPerfPBPlus(const char *dir="");
  AREXPORT virtual ~ArRobotPerfPBPlus() {}
};

class ArRobotPion1M : public ArRobotParams
{
public:
  AREXPORT ArRobotPion1M(const char *dir="");
  AREXPORT virtual ~ArRobotPion1M() {}
};

class ArRobotPion1X : public ArRobotParams
{
public:
  AREXPORT ArRobotPion1X(const char *dir="");
  AREXPORT virtual ~ArRobotPion1X() {}
};

class ArRobotPsos1M : public ArRobotParams
{
public:
  AREXPORT ArRobotPsos1M(const char *dir="");
  AREXPORT virtual ~ArRobotPsos1M() {}
};

class ArRobotPsos43M : public ArRobotParams
{
public:
  AREXPORT ArRobotPsos43M(const char *dir="");
  AREXPORT virtual ~ArRobotPsos43M() {}
};

class ArRobotPsos1X : public ArRobotParams
{
public:
  AREXPORT ArRobotPsos1X(const char *dir="");
  AREXPORT virtual ~ArRobotPsos1X() {}
};

class ArRobotPionAT : public ArRobotParams
{
public:
  AREXPORT ArRobotPionAT(const char *dir="");
  AREXPORT virtual ~ArRobotPionAT() {}
};

class ArRobotMapper : public ArRobotParams
{
public:
  AREXPORT ArRobotMapper(const char *dir="");
  AREXPORT virtual ~ArRobotMapper() {}
};

class ArRobotPowerBot : public ArRobotParams
{
public:
  AREXPORT ArRobotPowerBot(const char *dir="");
  AREXPORT virtual ~ArRobotPowerBot() {}
};

class ArRobotP3DXSH : public ArRobotParams
{
 public:
  AREXPORT ArRobotP3DXSH(const char *dir="");
  AREXPORT virtual ~ArRobotP3DXSH() {}
};

class ArRobotP3ATSH : public ArRobotParams
{
 public:
  AREXPORT ArRobotP3ATSH(const char *dir="");
  AREXPORT virtual ~ArRobotP3ATSH() {}
};

class ArRobotP3ATIWSH : public ArRobotParams
{
 public:
  AREXPORT ArRobotP3ATIWSH(const char *dir="");
  AREXPORT virtual ~ArRobotP3ATIWSH() {}
};

class ArRobotPatrolBotSH : public ArRobotParams
{
 public:
  AREXPORT ArRobotPatrolBotSH(const char *dir="");
  AREXPORT virtual ~ArRobotPatrolBotSH() {}
};

class ArRobotPeopleBotSH : public ArRobotParams
{
 public:
  AREXPORT ArRobotPeopleBotSH(const char *dir="");
  AREXPORT virtual ~ArRobotPeopleBotSH() {}
};

class ArRobotPowerBotSH : public ArRobotParams
{
 public:
  AREXPORT ArRobotPowerBotSH(const char *dir="");
  AREXPORT virtual ~ArRobotPowerBotSH() {}
};

class ArRobotWheelchairSH : public ArRobotParams
{
 public:
  AREXPORT ArRobotWheelchairSH(const char *dir="");
  AREXPORT virtual ~ArRobotWheelchairSH() {}
};

class ArRobotPowerBotSHuARCS : public ArRobotParams
{
 public:
  AREXPORT ArRobotPowerBotSHuARCS(const char *dir="");
  AREXPORT virtual ~ArRobotPowerBotSHuARCS() {}
};

class ArRobotSeekur : public ArRobotParams
{
 public:
  AREXPORT ArRobotSeekur(const char *dir="");
  AREXPORT virtual ~ArRobotSeekur() {}
};

/// @since Aria 2.7.2
class ArRobotMT400 : public ArRobotParams
{
 public:
  AREXPORT ArRobotMT400(const char *dir="");
  AREXPORT virtual ~ArRobotMT400() {}
};

/// @since Aria 2.7.2
class ArRobotResearchPB : public ArRobotParams
{
 public:
  AREXPORT ArRobotResearchPB(const char *dir="");
  AREXPORT virtual ~ArRobotResearchPB() {}
};

/// @since Aria 2.7.2
class ArRobotSeekurJr : public ArRobotParams
{
 public:
  AREXPORT ArRobotSeekurJr(const char *dir="");
  AREXPORT virtual ~ArRobotSeekurJr() {}
};

/// @since Aria 2.7.4
class ArRobotP3DXSH_lms1xx : public ArRobotP3DXSH
{
public: 
  AREXPORT ArRobotP3DXSH_lms1xx(const char *dir="");
};

/// @since Aria 2.7.4
class ArRobotP3ATSH_lms1xx : public ArRobotP3ATSH
{
public: 
  AREXPORT ArRobotP3ATSH_lms1xx(const char *dir="");
};

/// @since Aria 2.7.4
class ArRobotPeopleBotSH_lms1xx : public ArRobotPeopleBotSH
{
public: 
  AREXPORT ArRobotPeopleBotSH_lms1xx(const char *dir="");
};

/// @since Aria 2.7.4
class ArRobotP3DXSH_lms500 : public ArRobotP3DXSH
{
public: 
  AREXPORT ArRobotP3DXSH_lms500(const char *dir="");
};

/// @since Aria 2.7.4
class ArRobotP3ATSH_lms500 : public ArRobotP3ATSH
{
public: 
  AREXPORT ArRobotP3ATSH_lms500(const char *dir="");
};

/// @since Aria 2.7.4
class ArRobotPeopleBotSH_lms500 : public ArRobotPeopleBotSH
{
public: 
  AREXPORT ArRobotPeopleBotSH_lms500(const char *dir="");
};

/// @since Aria 2.7.4
class ArRobotPowerBotSH_lms500 : public ArRobotPowerBotSH
{
public: 
  AREXPORT ArRobotPowerBotSH_lms500(const char *dir="");
};

/// @since Aria 2.7.4
class ArRobotResearchPB_lms500 : public ArRobotResearchPB
{
public: 
  AREXPORT ArRobotResearchPB_lms500(const char *dir="");
};

/// @since Aria 2.8
class ArRobotPioneerLX : public ArRobotParams
{
public:
  AREXPORT ArRobotPioneerLX(const char *dir="");
  AREXPORT virtual ~ArRobotPioneerLX() {}
};

/** @endcond INCLUDE_INTERNAL_ROBOT_PARAM_CLASSES */

#endif // ARROBOTTYPES_H
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 /*
Adept MobileRobots Robotics Interface for Applications (ARIA)
Copyright (C) 2004-2005 ActivMedia Robotics LLC
Copyright (C) 2006-2010 MobileRobots Inc.
Copyright (C) 2011-2014 Adept Technology

     This program is free software; you can redistribute it and/or modify
     it under the terms of the GNU General Public License as published by
     the Free Software Foundation; either version 2 of the License, or
     (at your option) any later version.

     This program is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     GNU General Public License for more details.

     You should have received a copy of the GNU General Public License
     along with this program; if not, write to the Free Software
     Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

If you wish to redistribute ARIA under different terms, contact 
Adept MobileRobots for information about a commercial version of ARIA at 
robots@mobilerobots.com or 
Adept MobileRobots, 10 Columbia Drive, Amherst, NH 03031; +1-603-881-7960
*/
#ifndef ARACTIONDRIVEDISTANCE_H
#define ARACTIONDRIVEDISTANCE_H

#include "ariaTypedefs.h"
#include "ariaUtil.h"
#include "ArAction.h"

/// This action goes to a given ArPose very naively

/**
   This action naively drives a fixed distance. The action stops the
   robot when it has travelled the appropriate distance. It
   travels at 'speed' mm/sec.

   You can give it a distance with setDistance(), cancel its movement
   with cancelDistance(), and see if it got there with
   haveAchievedDistance().

   You can tell it to go backwards by calling setDistance with a
   negative value.

   This doesn't avoid obstacles or anything, you could add have an
   limiting ArAction at a higher priority to try to do this (so you
   don't smash things). (For truly intelligent navigation, see
   the ARNL or SONARNL software libraries.)
  @ingroup ActionClasses
**/


class ArActionDriveDistance : public ArAction
{
public:
  AREXPORT ArActionDriveDistance(const char *name = "driveDistance", 
				double speed = 400, double deceleration = 200);
  AREXPORT virtual ~ArActionDriveDistance();

  /// Sees if the goal has been achieved
  AREXPORT bool haveAchievedDistance(void);
  /// Cancels the goal the robot has
  AREXPORT void cancelDistance(void);
  /// Sets a new goal and sets the action to go there
  AREXPORT void setDistance(double distance, bool useEncoders = true);
  /// Gets whether we're using the encoder position or the normal position
  bool usingEncoders(void) { return myUseEncoders; }
  /// Sets the speed the action will travel at (mm/sec)
  void setSpeed(double speed = 400) { mySpeed = speed; }
  /// Gets the speed the action will travel at (mm/sec)
  double getSpeed(void) { return mySpeed; }
  /// Sets the deceleration the action will use (mm/sec/sec)
  void setDeceleration(double deceleration = 200) 
    { myDeceleration = deceleration; }
  /// Gets the deceleration the action will use (mm/sec/sec)
  double getDeceleration(void) { return myDeceleration; }
  /// Sets if we're printing or not
  void setPrinting(bool printing) { myPrinting = printing; }
  AREXPORT virtual ArActionDesired *fire(ArActionDesired currentDesired);
  AREXPORT virtual ArActionDesired *getDesired(void) { return &myDesired; }
#ifndef SWIG
  AREXPORT virtual const ArActionDesired *getDesired(void) const 
                                                        { return &myDesired; }
#endif
protected:
  double myDistance;
  bool myUseEncoders;
  double mySpeed;
  double myDeceleration;
  ArActionDesired myDesired;
  bool myPrinting;
  double myLastVel;

  double myDistTravelled;
  ArPose myLastPose;
  
  enum State
  {
    STATE_NO_DISTANCE, 
    STATE_ACHIEVED_DISTANCE,
    STATE_GOING_DISTANCE
  };
  State myState;
};

#endif // ARACTIONDRIVE
                                                                                                                                                                      #ifndef NLNETPACKETRECEIVERUDP_H
#define NLNETPACKETRECEIVERUDP_H

#include "ArNetPacket.h"

/**
   This is the receiver for UDP packets.
**/

class ArNetPacketReceiverUdp
{
public:
  AREXPORT ArNetPacketReceiverUdp();
  AREXPORT ~ArNetPacketReceiverUdp();
  
  /// Sets the socket this receiver uses
  AREXPORT void setSocket(ArSocket *socket);
  /// Gets the socket this receiver uses
  AREXPORT ArSocket *getSocket(void);

  /// Sets the callback for use when a packet is received
  AREXPORT void setProcessPacketCB(ArFunctor2<ArNetPacket *, 
				   struct sockaddr_in *> *functor);

  /// Gets the callback used when a packet is received
  AREXPORT ArFunctor2<ArNetPacket *, struct sockaddr_in *> *
                                                              getProcessPacketCB(void);
  
  /// Reads in all the data available calling the processPacketCB
  AREXPORT bool readData(void);

protected:
  ArFunctor2<ArNetPacket *, struct sockaddr_in *> *myProcessPacketCB;
  ArSocket *mySocket;
  ArTime myLastPacket;
  ArNetPacket myPacket;
  char myBuff[ArNetPacket::MAX_LENGTH+20];

};

#endif // NLNETPACKETRECEIVERUDP_H
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          #ifndef ARTEMPDIRECTORYHELPER_H
#define ARTEMPDIRECTORYHELPER_H

#include "ariaTypedefs.h"
#include "ArFunctor.h"

/// Helper class that manages the transition of temporary files to the base directory.
class ArTempDirectoryHelper 
{
public:

  /// Constructor
  AREXPORT ArTempDirectoryHelper(const char *baseDirectory = "",
				                         const char *tempDirectory = "");

  /// Destructor
  AREXPORT virtual ~ArTempDirectoryHelper();


  /// Returns the name of the directory for temporary files.
  AREXPORT const char *getTempDirectory();
  /// Returns the name of the target base directory.
  AREXPORT const char *getBaseDirectory();


  /// Creates a complete file path name for the specified file in the temporary directory.
  AREXPORT std::string makeTempFilePathName(const char *fileName);
 
  /// Creates a complete file path name for the specified file in the base directory.
  AREXPORT std::string makeBaseFilePathName(const char *fileName);


  /// Moves the specified file from the temporary directory to the base directory.
  AREXPORT bool moveFileToBaseDirectory(const char *fileName);
  
  /// Moves the specified files from the temporary directory to the base directory.
  AREXPORT bool moveFilesToBaseDirectory
                           (const std::list<std::string> &fileNameList);

  
  /// Adds a callback to be called before moving from temp dir to base dir
  AREXPORT void addPreMoveCallback(ArFunctor *functor, 
                                   ArListPos::Pos position = ArListPos::LAST);
  /// Removes a callback to be called before moving from temp dir to base dir
  AREXPORT void remPreMoveCallback(ArFunctor *functor);
  /// Adds a callback to be called after moving from temp dir to base dir
  AREXPORT void addPostMoveCallback(ArFunctor *functor, 
                                    ArListPos::Pos position = ArListPos::LAST);
  /// Removes a callback to be called after moving from temp dir to base dir
  AREXPORT void remPostMoveCallback(ArFunctor *functor);


protected:

  /// Creates a complete file path name for the specified file and directory.
  AREXPORT std::string makeFilePathName(const char *fileName,
                                        const char *dirName);
  
protected:

  /// Path name of the base directory  
  std::string myBaseDirectory;
  /// Path name of the temporary directory
  std::string myTempDirectory;

  /// List of callbacks invoked before the files are moved
  std::list<ArFunctor *> myPreMoveCallbacks;
  /// List of callbacks invoked after the files are moved
  std::list<ArFunctor *> myPostMoveCallbacks;

}; // end class ArTempDirectoryHelper

#endif // ARTEMPDIRECTORYHELPER_H


                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  #ifndef ARSERVERSIMPLEOPENER_H
#define ARSERVERSIMPLEOPENER_H

#include "Aria.h"

class ArServerBase;

/**
   @brief Set up and open an ArNetworking server

   Some program command line options affect behavior:
   @verbinclude ArServerSimpleOpener_options 

   To set the
   port the server uses use '-serverPort <i>serverPortNumber</i>' or
   '-sp <i>serverPortNumber</i>'.  To set the file to look in for user
   information use '-userInfo <i>fileName</i>' or "-ui
   <i>fileName</i>'.  To log out the user information use
   '-logUserInfo' or 'lui'.  To log out the command groups use
   '-logCommandGroups' or '-lcg'.  To set the key used for the server
   (that the client has to know to connect if using user and password)
   use '-serverInfoFile <i>file</i>'.  With a file that has in it
   'serverKey <i>serverKey</i>'.  You should obviously make sure no one you
   don't want to know that server key can read your file that it is
   in.

   For more details about all of these options see ArServerBase.

   @sa ArServerBase
**/
class ArServerSimpleOpener
{
public:
  /// Constructor 
  AREXPORT ArServerSimpleOpener(ArArgumentParser *parser, 
				const char *prefix = "", 
				bool addAriaCallbacks = true);
  /// Destructor
  AREXPORT ~ArServerSimpleOpener();
  /// Function to open up the server
  AREXPORT bool open(ArServerBase *server, const char *baseDirectory = "",
		     int secondsToTryFor = 240);
  /// Function to parse the arguments given in the constructor
  AREXPORT bool parseArgs(void);
  /// Function to parse the arguments given in an arbitrary parser
  AREXPORT bool parseArgs(ArArgumentParser *parser);
  /// Log the options the simple connector has
  AREXPORT void logOptions(void) const;
  /// Logs the things requested for logging, may check things later
  AREXPORT bool checkAndLog(void) const;
  /// Returns true if the open failed because of a bad user file
  bool wasUserFileBad(void) { return myBadUserFile; }
  /// Returns true if the open failed because it couldn't open
  bool didOpenFail(void) { return myOpenFailed; }
  /** Get the server's port number
   *  @return the server's port number
   */
  int getPort() { return myServerPort; } 

  /** Set default server port number (normally 7272). This must be called before
  * parsing command line arguments. 
  * @since 2.7.6
  */
  void setDefaultPort(int port) { myServerPort = port; }

  /// Parses the file for holding the server key
  AREXPORT bool parseFile(const char *fileName);
  /// Sets the tcpOnly flag
  void setServerTcpOnly(bool serverTcpOnly) { myTcpOnly = serverTcpOnly; }
  /// Gets the server key
  const char *getServerKey(void) { return myServerKey.c_str(); } 
protected:
  AREXPORT bool parseArgsWithOutPrefix(ArArgumentParser *parser);
  AREXPORT bool parseArgsWithPrefix(ArArgumentParser *parser);
  AREXPORT void logOptionsWithOutPrefix(void) const;
  AREXPORT void logOptionsWithPrefix(void) const;

  bool fileServerKeyCallback(ArArgumentBuilder *arg);
  
  void reset(void);
  const char *myUserFile;
  //const char *myServerKey;
  std::string myServerKey;
  int myServerPort;
  const char *myOpenOnIP;
  ArServerBase *myServer;
  bool myLogUserInfo;
  bool myLogCommandGroups;
  bool myTcpOnly;
  bool myBadUserFile;
  bool myOpenFailed;
  // our parser
  ArArgumentParser *myParser;
  bool myOwnParser;
  std::string myPrefix;

  // file parser for the server key file
  ArFileParser myFileParser;
  ArRetFunctorC<bool, ArServerSimpleOpener> myParseArgsCB;
  ArConstFunctorC<ArServerSimpleOpener> myLogOptionsCB;
  ArRetFunctor1C<bool, ArServerSimpleOpener, 
      ArArgumentBuilder *> myFileServerKeyCB;
};

#endif // ARSERVERSIMPLEOPENER_H
                                                                                                                                                                                                                                                                                                                                                                                                                                               /*
  This is the software we use for doing the md5 checksums, its from 
  http://sourceforge.net/project/showfiles.php?group_id=42360
*/

/*
  Copyright (C) 1999, 2002 Aladdin Enterprises.  All rights reserved.

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  L. Peter Deutsch
  ghost@aladdin.com

 */
/*
  Independent implementation of MD5 (RFC 1321).

  This code implements the MD5 Algorithm defined in RFC 1321, whose
  text is available at
	http://www.ietf.org/rfc/rfc1321.txt
  The code is derived from the text of the RFC, including the test suite
  (section A.5) but excluding the rest of Appendix A.  It does not include
  any code or documentation that is identified in the RFC as being
  copyrighted.

  The original and principal author of md5.h is L. Peter Deutsch
  <ghost@aladdin.com>.  Other authors are noted in the change history
  that follows (in reverse chronological order):

  2002-04-13 lpd Removed support for non-ANSI compilers; removed
	references to Ghostscript; clarified derivation from RFC 1321;
	now handles byte order either statically or dynamically.
  1999-11-04 lpd Edited comments slightly for automatic TOC extraction.
  1999-10-18 lpd Fixed typo in header comment (ansi2knr rather than md5);
	added conditionalization for C++ compilation from Martin
	Purschke <purschke@bnl.gov>.
  1999-05-03 lpd Original version.
 */

#ifndef md5_INCLUDED
#  define md5_INCLUDED

/*
 * This package supports both compile-time and run-time determination of CPU
 * byte order.  If ARCH_IS_BIG_ENDIAN is defined as 0, the code will be
 * compiled to run only on little-endian CPUs; if ARCH_IS_BIG_ENDIAN is
 * defined as non-zero, the code will be compiled to run only on big-endian
 * CPUs; if ARCH_IS_BIG_ENDIAN is not defined, the code will be compiled to
 * run on either big- or little-endian CPUs, but will run slightly less
 * efficiently on either one than if ARCH_IS_BIG_ENDIAN is defined.
 */

typedef unsigned char md5_byte_t; /* 8-bit byte */
typedef unsigned int md5_word_t; /* 32-bit word */

/* Define the state of the MD5 Algorithm. */
typedef struct md5_state_s {
    md5_word_t count[2];	/* message length in bits, lsw first */
    md5_word_t abcd[4];		/* digest buffer */
    md5_byte_t buf[64];		/* accumulate block */
} md5_state_t;

// MPL (ActivMedia) taking out the extern since its only being used in c++
/*
#ifdef __cplusplus
extern "C" 
{
#endif
*/

// RH (ActivMedia/MobileRobots) Added "AREXPORT" symbol to all public functions. On Windows, this must be defined
// to either import or export the symbols to/from DLLs. On other platforms, it should be defined to be nothing.

/* Initialize the algorithm. */
AREXPORT void md5_init(md5_state_t *pms);

/* Append a string to the message. */
AREXPORT void md5_append(md5_state_t *pms, const md5_byte_t *data, int nbytes);

/* Finish the message and return the digest. */
AREXPORT void md5_finish(md5_state_t *pms, md5_byte_t digest[16]);

/// MPL (ActivMedia) taking out the extern since its only being used in c++
/*
#ifdef __cplusplus
}  // end extern "C"
#endif
*/

#endif /* md5_INCLUDED */
                                                                                                                                                                                                             #ifndef ARSERVERCONFIGHANDLER_H
#define ARSERVERCONFIGHANDLER_H

#include "Aria.h"
#include "ArServerBase.h"

class ArServerClient;

/// Class for sending and receiving ArConfig data via ArNetworking.
/**
 * ArServerHandlerConfig defines the network packet handlers used to transmit
 * ArConfig objects to a client, and to modify them based on information 
 * received from the client.  Since the packet structure for the ArConfig is 
 * rather complex, this class is best used in conjunction with the 
 * ArClientHandlerConfig.
 * 
 * This class handles the following requests:
 *  <ul>
 *    <li>getConfigBySections/getConfigBySectionsV2:  Replies with multiple 
 *        packets, one for each ArConfig section plus an empty packet that 
 *        terminates the reply.  Each packet contains the following header 
 *        information:
 *        <ol> 
 *          <li>Section Indicator: Always set to 'S' (byte)</li>
 *          <li>Section Name: (string)</li>
 *          <li>Section Comment: (string) </li>  
 *          <li>Section Category Name: (string) Only for getConfigBySectionsV2 </li>
 *        </ol>
 *        For each parameter in the section, the packet then contains a 
 *        a Parameter Indicator (always set to 'P' (byte)) followed by a 
 *        complete description of the parameter (display hints are included).  
 *        See ArClientArgUtils for more information.
 *    </li>
 *    <li>getConfig:  This request has been superceded by getConfigBySections. (It
 *        replies with a single packet containing all of the ArConfig 
 *        sections as described above.  If the ArConfig is large, then it 
 *        may not be sent successfully.  In addition, it contains no parameter
 *        display hints.)
 *    </li>
 *    <li>setConfig: Parses the received packet and updates the robot's 
 *        ArConfig (and saves it to the file).  For each modified section, 
 *        the received packet is expected to contain:
 *        <ol>
 *          <li>Section Indicator: Always set to "Section" (string)</li>
 *          <li>Section Name: (string) </li>
 *        </ol>
 *        Followed by a brief "text" description of each modified parameter.
 *        This is the parameter name (string) followed by the parameter value
 *        formatted as text (string).  See ArClientArgUtils for more information.
 *        
 *        A reply packet containing a string is sent to the client. If the 
 *        string is empty, then the config was successfully updated.  Otherwise,
 *        the string contains the name of the first parameter that caused an
 *        error during the update handling.
 *    </li>
 *    <li>reloadConfig: Reloads the ArConfig from the text file. 
 *    </li>
 *    <li>configUpdated: An empty packet is broadcast to all interested clients
 *        after setConfig or reloadConfig has been completed.  The clients may
 *        then request the modified ArConfig data with getConfigBySections
 *        (or getConfig).
 *    </li>
 *    <li>getConfigDefaults: If a "default" configuration file is available,
 *        then this command can be used to send the preferred default values
 *        to the client.  The received packet should contain a single string,
 *        which is the name of the section to be retrieved, or an empty string
 *        to indicate all sections.  
 *        
 *        For each requested section, the reply packet contains:
 *        <ol>
 *          <li>Section Indicator: Always set to "Section" (string)</li>
 *          <li>Section Name: (string) </li>
 *        </ol>
 *        Followed by a brief "text" description of each default parameter value.
 *        This is the parameter name (string) followed by the parameter value
 *        formatted as text (string).  See ArClientArgUtils for more information.
 *    </li>
 *  </ul>
 * 
 *  If you are using this class with the default file option you'll
 *  want to make it AFTER you're done adding things to the config, ie
 *  last, so that the default code can work correctly (it needs to know
 *  about all the info).
**/
class ArServerHandlerConfig
{
public:

  /// Constructor
  /**
   * @param server the ArServerBase * used to send and receive network packets;
   * must be non-NULL
   * @param config the ArConfig * that is maintained by this server handler
   * @param defaultFile the char * name of the file that contains the default
   * values for the ArConfig; if NULL, then getConfigDefaults will not be
   * supported
   * @param defaultFileBaseDirectory the char * name of the directory that
   * contains the default file
  **/
  AREXPORT ArServerHandlerConfig(ArServerBase *server, 
                                 ArConfig *config,
                                 const char *defaultFile = NULL, 
                                 const char *defaultFileBaseDirectory = NULL,
                                 bool allowFactory = true,
                                 const char *robotName = NULL,
                                 bool preventChanges = false,
                                 const char *preventChangesString = NULL);
  
  /// Destructor
  AREXPORT virtual ~ArServerHandlerConfig();

  // ---------------------------------------------------------------------------
  // Network Packet Handlers 
  // ---------------------------------------------------------------------------

  /// Handles the "reloadConfig" request.
  AREXPORT void reloadConfig(ArServerClient *client, ArNetPacket *packet);

  /// Handles the "getConfigBySections" request.
  AREXPORT void getConfigBySections(ArServerClient *client, ArNetPacket *packet);

  /// Handles the "getConfigBySectionsV2" request.
  AREXPORT void getConfigBySectionsV2(ArServerClient *client, ArNetPacket *packet);

  /// Handles the "getConfigBySectionsV3" request.
  AREXPORT void getConfigBySectionsV3(ArServerClient *client, ArNetPacket *packet);
  
  /// Handles the "getConfigBySectionsV4" request.
  AREXPORT void getConfigBySectionsV4(ArServerClient *client, ArNetPacket *packet);

  /// Handles the (deprecated) "getConfig" request.
  AREXPORT void getConfig(ArServerClient *client, ArNetPacket *packet);
  
  /// Handles the "setConfig" request.
  AREXPORT void setConfig(ArServerClient *client, ArNetPacket *packet);
  
  /// Handles the "setConfigParam" request.
  AREXPORT void setConfigParam(ArServerClient *client, ArNetPacket *packet);
  
  AREXPORT void setConfigBySections(ArServerClient *client, ArNetPacket *packet);
  
  AREXPORT void setConfigBySectionsV2(ArServerClient *client, ArNetPacket *packet);

  /// Handles the "getConfigDefaults" request.
  AREXPORT void getConfigDefaults(ArServerClient *client, ArNetPacket *packet);

  /// Handles the "getConfigSectionFlags" request.
  AREXPORT void getConfigSectionFlags(ArServerClient *client, 
				                              ArNetPacket *packet);

  /// Handles the "getLastEditablePriority" request.
  AREXPORT void getLastEditablePriority(ArServerClient *client,
                                        ArNetPacket *packet);

  // ---------------------------------------------------------------------------
  // Callback Methods
  // ---------------------------------------------------------------------------

  /// Adds a callback to be called before writing to disk
  AREXPORT void addPreWriteCallback(ArFunctor *functor, 
                                    ArListPos::Pos position = ArListPos::LAST);
  /// Removes a callback to be called before writing to disk
  AREXPORT void remPreWriteCallback(ArFunctor *functor);

  /// Adds a callback to be called after writing to disk
  AREXPORT void addPostWriteCallback(ArFunctor *functor, 
                                     ArListPos::Pos position = ArListPos::LAST);
  /// Removes a callback to be called after writing to disk
  AREXPORT void remPostWriteCallback(ArFunctor *functor);  

  /// Adds a callback to be called when the config is updated
  AREXPORT void addConfigUpdatedCallback(ArFunctor *functor, 
				                ArListPos::Pos position = ArListPos::LAST);
  /// Removes a callback to be called w
# Let's Search! JSON Search Engine

![TotalViewsBadge](https://hitscounter.dev/api/hit?url=https%3A%2F%2Fgithub.com%2Fluisegarduno%2FJSON_SearchEngine&label=Total-Views&icon=github&color=%236ea8fe)

### Test JSON Datasets (SCOTUS Opinions) : 
- [__Small__ ](https://www.dropbox.com/s/hxep4wthstqkrs9/scotus-small.tar.xz?dl=0) : (50 Files)
- [__Medium__ ](https://www.dropbox.com/s/8zdm3zl06fqmg24/scotus-med.tar.xz?dl=0) : (502 Files) ⬅ *__Recommended__* 
- [__Large__ ](https://web.archive.org/web/20210715231147/https://www.courtlistener.com/api/bulk-data/opinions/ca1.tar.gz) : (35,587 Files)

## Instructions on how to use:
1. Run program & select __*Maintenance*__ in the Main Menu

2. Your file browser will open once __*Add Folder*__ is pressed. After selecting a directory, wait for the data to load into the index.
<table>
  <tr>   <th>Selecting a Directory</th>   </tr>
  <tr>   <td><img src="https://github.com/luisegarduno/JSON_SearchEngine/blob/master/SearchEngine/Images/AddFiles.gif"  /></td>    </tr>
</table>

3. Return to the Main Menu & select __*Interactive*__. Then select __*Index Method*__ to choose your index method of choice as seen below.
<table>
  <tr>   <th>Choosing an Index Method</th>   </tr>
  <tr>   <td><img src="https://github.com/luisegarduno/JSON_SearchEngine/blob/master/SearchEngine/Images/IndexMethod.gif"  /> </td>   </tr>
</table>

4. Select __*Search*__ to enter a new query.
<table>
  <tr>   <th>Entering a Search Query</th>   </tr>
  <tr>   <td><img src="https://github.com/luisegarduno/JSON_SearchEngine/blob/master/SearchEngine/Images/SearchQuery.gif"  /> </td>   </tr>
</table>


 Examples of different available boolean pre-fixes & how they can be used : 
 > Education                  : Returns all opinions that contain the word education.
 
 > __OR__ privacy security    : Returns all opinions that contain either privacy OR security OR both.
 
 > security __NOT__ privacy   : Returns all opinions that contain security, but not privacy.
 
 > __AND__ higher education texas : Returns all opinions that contain the words higher and education and texas
 
 > __AND__ privacy security NOT computer : Returns all opinions that contain privacy and security, but not computer.
 

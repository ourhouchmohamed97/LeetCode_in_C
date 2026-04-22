// Words Within Two Edits of Dictionary

#include <stdbool.h>
#include <unistd.h>

bool is_valid_query( char const *query, char const *dictionaryEntry )
{
    size_t len = strlen( query );

    int numDifferences = 0;
    for( size_t i = 0; i < len; ++i )
    {
        if( query[i] != dictionaryEntry[i] )
        {
            ++numDifferences;
        }

        if( numDifferences > 2 )
        {
            return false;
        }
    }

    return true;
}

char** twoEditWords( char **queries, int queriesSize, char **dictionary, int dictionarySize, int *returnSize )
{
    int numValid = 0;
    static char *validEntries[100];

    for( int iQuery = 0; iQuery < queriesSize; ++iQuery )
    {
        for( int iDicEntry = 0; iDicEntry < dictionarySize; ++iDicEntry )
        {
            if( is_valid_query( queries[iQuery], dictionary[iDicEntry] ) )
            {
                validEntries[numValid] = queries[iQuery];
                ++numValid;

                break;
            }
        }
    }

    *returnSize = numValid;
    return validEntries;
}
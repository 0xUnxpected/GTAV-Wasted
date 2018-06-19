/*
*							GTA V Styled Wasted Screen
*							By #Samurai aka Un[x]pected
*/

new Text:WastedTD[2];
new PlayerText:WastedPTD[MAX_PLAYERS][2];

public OnGameModeInit()
{
	WastedTD[0] = TextDrawCreate(2.5000, 2.1666, "Box"); // nope
	TextDrawLetterSize(WastedTD[0], 0.0000, 49.4375);
	TextDrawTextSize(WastedTD[0], 640.0000, 0.0000);
	TextDrawAlignment(WastedTD[0], 1);
	TextDrawColor(WastedTD[0], -1);
	TextDrawUseBox(WastedTD[0], 1);
	TextDrawBoxColor(WastedTD[0], 104);
	TextDrawSetOutline(WastedTD[0], 0);
	TextDrawBackgroundColor(WastedTD[0], 255);
	TextDrawFont(WastedTD[0], 1);
	TextDrawSetProportional(WastedTD[0], 1);
	TextDrawSetShadow(WastedTD[0], 0);

	WastedTD[1] = TextDrawCreate(0.6250, 173.0833, "Box"); // nope
	TextDrawLetterSize(WastedTD[1], 0.0000, 7.6875);
	TextDrawTextSize(WastedTD[1], 702.0000, 0.0000);
	TextDrawAlignment(WastedTD[1], 1);
	TextDrawColor(WastedTD[1], -1);
	TextDrawUseBox(WastedTD[1], 1);
	TextDrawBoxColor(WastedTD[1], 93);
	TextDrawSetOutline(WastedTD[1], 0);
	TextDrawBackgroundColor(WastedTD[1], 255);
	TextDrawFont(WastedTD[1], 1);
	TextDrawSetProportional(WastedTD[1], 1);
	TextDrawSetShadow(WastedTD[1], 0);
	#if defined WASTED_OGMI
		return WASTED_OGMI();
	#else
		return 1;
	#endif
}

#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit WASTED_OGMI
#if defined WASTED_OGMI
	forward WASTED_OGMI();
#endif

public OnPlayerConnect(playerid)
{
	WastedPTD[playerid][0] = CreatePlayerTextDraw(playerid, 315.6250, 177.1667, "WASTED"); // nope
	PlayerTextDrawLetterSize(playerid, WastedPTD[playerid][0], 1.3212, 4.4699);
	PlayerTextDrawAlignment(playerid, WastedPTD[playerid][0], 2);
	PlayerTextDrawColor(playerid, WastedPTD[playerid][0], -16776961);
	PlayerTextDrawSetOutline(playerid, WastedPTD[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, WastedPTD[playerid][0], 255);
	PlayerTextDrawFont(playerid, WastedPTD[playerid][0], 3);
	PlayerTextDrawSetProportional(playerid, WastedPTD[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, WastedPTD[playerid][0], 0);

	WastedPTD[playerid][1] = CreatePlayerTextDraw(playerid, 315.6750, 223.8331, ""); // nope
	PlayerTextDrawLetterSize(playerid, WastedPTD[playerid][1], 0.1662, 0.8533);
	PlayerTextDrawAlignment(playerid, WastedPTD[playerid][1], 2);
	PlayerTextDrawColor(playerid, WastedPTD[playerid][1], -1);
	PlayerTextDrawSetOutline(playerid, WastedPTD[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, WastedPTD[playerid][1], 255);
	PlayerTextDrawFont(playerid, WastedPTD[playerid][1], 2);
	PlayerTextDrawSetProportional(playerid, WastedPTD[playerid][1], 1);
	PlayerTextDrawSetShadow(playerid, WastedPTD[playerid][1], 0);	
	#if defined WASTED_OPC
		return WASTED_OPC(playerid);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect WASTED_OPC
#if defined WASTED_OPC
	forward WASTED_OPC(playerid);
#endif	

public OnPlayerDeath(playerid, killerid, reason)
{
	new wasted_str[46];
	if(killerid == playerid || killerid == INVALID_PLAYER_ID) format(wasted_str, 20, "You committed suicide");
	if(killerid != playerid && killerid != INVALID_PLAYER_ID)
	{
		new name[24];
		GetPlayerName(killerid, name, 24);
		switch(reason)
		{
			case 0..3, 5..7, 10..15: format(wasted_str, 45, "Player %s beat you to death", name);
			case 4,8,9: format(wasted_str, 45, "You were knifed by %s", name);
			case 16, 35, 36, 39: format(wasted_str, 45, "%s blew you up", name);
			case 18, 37: format(wasted_str, 45, "You burned in the %s's fire", name);
			case 22..34, 38: format(wasted_str, 45, "You were shot by %s", name);
			case 40, 42: format(wasted_str, 45, "%s killed you", name);
		}
	}
	#if defined _crp_included
		PlayerTextDrawSetString(playerid, WastedPTD[playerid][0], "Dead");
		PlayerTextDrawSetString(playerid, WastedPTD[playerid][1], wasted_str);
	else
		PlayerTextDrawSetString(playerid, WastedPTD[playerid][0], "Dead");
		PlayerTextDrawSetString(playerid, WastedPTD[playerid][1], TranslateText(wasted_str));
	#endif

	TextDrawShowForPlayer(playerid, WastedTD[0]);
	TextDrawShowForPlayer(playerid, WastedTD[1]);
	PlayerTextDrawShow(playerid, WastedPTD[playerid][0]);
	PlayerTextDrawShow(playerid, WastedPTD[playerid][1]);
	#if defined WASTED_DEATH
		return WASTED_DEATH(playerid, killerid, reason);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnPlayerDeath
	#undef OnPlayerDeath
#else
	#define _ALS_OnPlayerDeath
#endif
#define OnPlayerDeath WASTED_DEATH
#if defined WASTED_DEATH
	forward WASTED_DEATH(playerid, killerid, reason);
#endif

public OnPlayerSpawn(playerid)
{
	TextDrawHideForPlayer(playerid, WastedTD[0]);
	TextDrawHideForPlayer(playerid, WastedTD[1]);
	PlayerTextDrawHide(playerid, WastedPTD[playerid][0]);
	PlayerTextDrawHide(playerid, WastedPTD[playerid][1]);
	#if defined WASTED_SPAWN
		return WASTED_SPAWN(playerid);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnPlayerSpawn
	#undef OnPlayerSpawn
#else
	#define _ALS_OnPlayerSpawn
#endif
#define OnPlayerSpawn WASTED_SPAWN
#if defined WASTED_SPAWN
	forward WASTED_SPAWN(playerid);
#endif

public OnPlayerRequestClass(playerid, classid)
{
	TextDrawHideForPlayer(playerid, WastedTD[0]);
	TextDrawHideForPlayer(playerid, WastedTD[1]);
	PlayerTextDrawHide(playerid, WastedPTD[playerid][0]);
	PlayerTextDrawHide(playerid, WastedPTD[playerid][1]);
	#if defined WASTED_CLASS
		return WASTED_CLASS(playerid, classid);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnPlayerRequestClass
	#undef OnPlayerRequestClass
#else
	#define _ALS_OnPlayerRequestClass
#endif
#define OnPlayerRequestClass WASTED_CLASS
#if defined WASTED_CLASS
	forward WASTED_CLASS(playerid, classid);
#endif
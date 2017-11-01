object Module: TModule
  OldCreateOrder = False
  Height = 578
  Width = 1043
  object GodConnection: TFDConnection
    Params.Strings = (
      'Database=god'
      'User_Name=wuming'
      'Password=22451010'
      'Server=redmine.jetfire.com.tw'
      'CharacterSet=utf8'
      'DriverID=MySQL')
    LoginPrompt = False
    BeforeConnect = GodConnectionBeforeConnect
    Left = 30
    Top = 7
  end
  object DataTable: TFDQuery
    Connection = GodConnection
    SQL.Strings = (
      'SELECT * FROM god.`data`')
    Left = 31
    Top = 68
    object DataTablecontent: TWideStringField
      FieldName = 'content'
      Origin = 'content'
      Required = True
      Size = 255
    end
    object DataTableexplanation: TWideStringField
      FieldName = 'explanation'
      Origin = 'explanation'
      Required = True
      Size = 1024
    end
    object DataTablename: TWideStringField
      FieldName = 'name'
      Origin = '`name`'
      Required = True
      Size = 10
    end
    object DataTableid: TShortintField
      AutoGenerateValue = arAutoInc
      FieldName = 'id'
      Origin = 'id'
      ProviderFlags = [pfInWhere, pfInKey]
    end
    object DataTableganzhi: TWideStringField
      FieldName = 'ganzhi'
      Origin = 'ganzhi'
      Required = True
      Size = 4
    end
    object DataTablegua: TWideStringField
      FieldName = 'gua'
      Origin = 'gua'
      Required = True
      Size = 10
    end
    object DataTablepregnant: TWideStringField
      FieldName = 'pregnant'
      Origin = 'pregnant'
      Required = True
      Size = 30
    end
    object DataTablefortune: TWideStringField
      FieldName = 'fortune'
      Origin = 'fortune'
      Required = True
      Size = 30
    end
    object DataTablemarriage: TWideStringField
      FieldName = 'marriage'
      Origin = 'marriage'
      Required = True
      Size = 30
    end
    object DataTablefame: TWideStringField
      FieldName = 'fame'
      Origin = 'fame'
      Required = True
      Size = 30
    end
    object DataTablefamily_fortune: TWideStringField
      FieldName = 'family_fortune'
      Origin = 'family_fortune'
      Required = True
      Size = 30
    end
    object DataTablewealth: TWideStringField
      FieldName = 'wealth'
      Origin = 'wealth'
      Required = True
      Size = 30
    end
    object DataTablebusiness: TWideStringField
      FieldName = 'business'
      Origin = 'business'
      Required = True
      Size = 30
    end
    object DataTablesick: TWideStringField
      FieldName = 'sick'
      Origin = 'sick'
      Required = True
      Size = 30
    end
  end
  object ResultTable: TFDQuery
    Connection = GodConnection
    SQL.Strings = (
      'SELECT * FROM god.result')
    Left = 108
    Top = 68
  end
  object UserTable: TFDQuery
    Connection = GodConnection
    SQL.Strings = (
      'SELECT * FROM god.`user`')
    Left = 178
    Top = 72
    object UserTablegender: TShortintField
      AutoGenerateValue = arDefault
      FieldName = 'gender'
      Origin = 'gender'
    end
    object UserTableage: TShortintField
      AutoGenerateValue = arDefault
      FieldName = 'age'
      Origin = 'age'
    end
    object UserTableeducation: TShortintField
      AutoGenerateValue = arDefault
      FieldName = 'education'
      Origin = 'education'
    end
    object UserTablereligion: TShortintField
      AutoGenerateValue = arDefault
      FieldName = 'religion'
      Origin = 'religion'
    end
    object UserTablecountry: TShortintField
      AutoGenerateValue = arDefault
      FieldName = 'country'
      Origin = 'country'
    end
    object UserTableexperience: TShortintField
      AutoGenerateValue = arDefault
      FieldName = 'experience'
      Origin = 'experience'
    end
    object UserTableid: TFDAutoIncField
      FieldName = 'id'
      Origin = 'id'
      ProviderFlags = [pfInWhere, pfInKey]
      ReadOnly = True
    end
  end
  object FDGUIxWaitCursor1: TFDGUIxWaitCursor
    Provider = 'FMX'
    Left = 968
    Top = 520
  end
  object FDPhysMySQLDriverLink1: TFDPhysMySQLDriverLink
    Left = 840
    Top = 520
  end
end
